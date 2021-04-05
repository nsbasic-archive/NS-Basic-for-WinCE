// NSBFormObjectView.cpp : implementation file
//

#include "stdafx.h"
#include "VNSB.h"
#include "NSBFormObjectView.h"

#include "VNSBDoc.h"
#include "VNSBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNSBFormObjectView

IMPLEMENT_DYNAMIC( CNSBFormObjectView, CWnd )

CNSBFormObjectView::CNSBFormObjectView()
{
}

CNSBFormObjectView::CNSBFormObjectView( CNSBFormObject *pFormOb, CWnd *pParent )
{
   m_pFormOb = pFormOb;
   CRect bounds = m_pFormOb->m_rectBounds;
   bounds.InflateRect( 2, 2 );
   Create( m_pFormOb->m_strObjectName, WS_CHILD | WS_VISIBLE | CS_DBLCLKS,
           bounds, pParent, m_pFormOb->m_nObjectID );
   SetWindowPos( &wndTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
   m_bSelected = FALSE;
   m_nDragHandle = 0;
   m_bRectChanged = FALSE;
   if( m_pFormOb->m_nObjectType == NSBOB_COM_OB )
      m_pFormOb->m_pComObDesc = ( (CVNSBView *)GetParent() )->GetDocument()->GetComObDesc( m_pFormOb->m_strObjectType );
}

CNSBFormObjectView::~CNSBFormObjectView()
{
}

LPCTSTR CNSBFormObjectView::m_lpszClassName = NULL;

BOOL CNSBFormObjectView::Create( LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext )
{
   if( m_lpszClassName == NULL )
      m_lpszClassName = AfxRegisterWndClass( CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW );
   return CWnd::Create( m_lpszClassName, lpszWindowName, dwStyle, rect,
      pParentWnd, nID, pContext );
} // Create

BEGIN_MESSAGE_MAP(CNSBFormObjectView, CWnd)
	//{{AFX_MSG_MAP(CNSBFormObjectView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CNSBFormObjectView message handlers

void CNSBFormObjectView::Select( BOOL bSelect )
{
   m_bSelected = bSelect;
   if( !m_bSelected )
      m_nDragHandle = 0;
   Invalidate();
} // Select

void CNSBFormObjectView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
   CRect rect;
   this->GetClientRect( &rect );

   // Ghost rectangle
//   dc.SetBkMode( TRANSPARENT );
//   GetParent()->InvalidateRect( rect );
   dc.FillSolidRect( rect, RGB( 255, 255, 255 ) );
   rect.DeflateRect( SELECT_INDENT, SELECT_INDENT );
   dc.Rectangle( rect );
   rect.InflateRect( SELECT_INDENT, SELECT_INDENT );

   // Text
   CString strText;
   this->GetWindowText( strText );
//   strText.Format( _T( "%s (%s)" ), strText, m_bSelected ? _T( "+" ) : _T( "-" ) );
   dc.DrawText( strText, -1, &rect, DT_CENTER | DT_VCENTER );

   if( m_bSelected )
   {
      COLORREF color = RGB( 0, 0, 0 );
      CSize sz( SELECT_HANDLE, SELECT_HANDLE );
      int nLoc;
      // Top
      dc.FillSolidRect( CRect( CPoint( 0, 0 ), sz ), color );
      nLoc = rect.right - SELECT_HANDLE;
      dc.FillSolidRect( CRect( CPoint( nLoc / 2, 0 ), sz ), color );
      dc.FillSolidRect( CRect( CPoint( nLoc, 0 ), sz ), color );
      // Vertical middles
      nLoc = ( rect.bottom - SELECT_HANDLE ) / 2;
      dc.FillSolidRect( CRect( CPoint( 0, nLoc ), sz ), color );
      dc.FillSolidRect( CRect( CPoint( rect.right - SELECT_HANDLE, nLoc ), sz ), color );
      // Bottom
      nLoc = rect.bottom - SELECT_HANDLE;
      dc.FillSolidRect( CRect( CPoint( 0, nLoc ), sz ), color );
      dc.FillSolidRect( CRect( CPoint( ( rect.right - SELECT_HANDLE ) / 2, nLoc ), sz ), color );
      dc.FillSolidRect( CRect( CPoint( rect.right - SELECT_HANDLE, nLoc ), sz ), color );
   }
} // OnPaint

void CNSBFormObjectView::OnLButtonDown( UINT nFlags, CPoint point )
{
   m_ptClick = point;
//   CString strMessage;
//   strMessage.Format( _T( "point: %d %d" ), point.x, point.y );
//   AfxMessageBox( strMessage );
   SetCapture();
   if( m_bSelected )
      SetDragHandle();
   ( (CVNSBView *)GetParent() )->Select( this, ( nFlags & MK_SHIFT ) != 0 );
   CWnd::OnLButtonDown( nFlags, point );
} // OnLButtonDown

void CNSBFormObjectView::OnLButtonUp( UINT nFlags, CPoint point )
{
   CVNSBView *pView = (CVNSBView *)GetParent();
   if( !m_bRectChanged && !( nFlags & MK_SHIFT ) )
      pView->Select( this, FALSE );
   if( m_bRectChanged )
   {
      m_bRectChanged = FALSE; // Update document, notifying of position changes
      pView->SelectionChangeRect();
   }
   ReleaseCapture();
   GetParent()->Invalidate();
   CWnd::OnLButtonUp( nFlags, point );
} // OnLButtonUp

void CNSBFormObjectView::OnMouseMove( UINT nFlags, CPoint point ) 
{
   if( GetCapture() == this )
      ( (CVNSBView *)GetParent() )->FormObjectDrag( point - m_ptClick, m_nDragHandle );
	CWnd::OnMouseMove( nFlags, point );
} // OnMouseMove

void CNSBFormObjectView::OnLButtonDblClk( UINT nFlags, CPoint point )
{
   CWnd::OnLButtonDblClk( nFlags, point );
   if( !( nFlags & ( MK_SHIFT | MK_CONTROL ) ) )
      ( (CVNSBView *)GetParent() )->SelectionEditProperties();
} // OnLButtonDblClk

void CNSBFormObjectView::SetDragHandle()
{
   CRect rect;
   this->GetClientRect( &rect );
   INT nLoc, nRow, nCol;

   m_nDragHandle = 0;
   nRow = 0;
   if( m_ptClick.y < SELECT_HANDLE )
      nRow = 1;
   if( nRow == 0 )
   {
      nLoc = ( rect.Height() - SELECT_HANDLE ) / 2;
      if( m_ptClick.y >= nLoc && m_ptClick.y < nLoc + SELECT_HANDLE )
         nRow = 2;
   }
   if( nRow == 0 )
   {
      nLoc = rect.Height() - SELECT_HANDLE;
      if( m_ptClick.y >= nLoc && m_ptClick.y < nLoc + SELECT_HANDLE )
         nRow = 3;
   }
   if( nRow == 0 )
      return;

   nCol = 0;
   if( m_ptClick.x < SELECT_HANDLE )
      nCol = 1;
   if( nCol == 0 && nRow != 2 )
   {
      nLoc = ( rect.Width() - SELECT_HANDLE ) / 2;
      if( m_ptClick.x >= nLoc && m_ptClick.x < nLoc + SELECT_HANDLE )
         nCol = 2;
   }
   if( nCol == 0 )
   {
      nLoc = rect.Width() - SELECT_HANDLE;
      if( m_ptClick.x >= nLoc && m_ptClick.x < nLoc + SELECT_HANDLE )
         nCol = 3;
   }
   if( nCol == 0 )
      return;
   m_nDragHandle = ( nRow - 1 ) * 3 + nCol;
} // SetDragHandle

void CNSBFormObjectView::DoDrag( CPoint ptDelta, int nGrid, int nDragHandle )
{
   // We're being dragged around by our middle, so just move
   if( nDragHandle == 0 )
      DoMove( ptDelta.x, ptDelta.y, nGrid );
   else // We're being dragged by a handle, so resize
      DoResize( ptDelta.x, ptDelta.y, nDragHandle, nGrid );
} // DoDrag

void CNSBFormObjectView::AdjustClickPoint( int nDragHandle, CRect &newBounds )
{
   CRect bounds;
   GetClientRect( bounds );

   switch( nDragHandle )
   {
   case 1:
   case 2:
   case 4:
      // Don't adjust click from topleft, top, or left handle
      break;
   case 3:
   case 6:
      // Adjust x
      m_ptClick.x = newBounds.Width() - ( bounds.right - m_ptClick.x );
      break;
   case 7:
   case 8:
      // Adjust y
      m_ptClick.y = newBounds.Height() - ( bounds.bottom - m_ptClick.y );
      break;
   case 9:
      // Adjust x and y
      m_ptClick.x = newBounds.Width() - ( bounds.right - m_ptClick.x );
      m_ptClick.y = newBounds.Height() - ( bounds.bottom - m_ptClick.y );
      break;
   default:
      ASSERT( 0 );
   }
} // AdjustClickPoint

void CNSBFormObjectView::DoMove( int cx, int cy, int nGrid )
{
   CRect bounds;

   // Get our parent-relative bounds
   GetWindowRect( bounds );
   GetParent()->ScreenToClient( bounds );

   // Calculate our new rect and move window
   bounds.OffsetRect( cx, cy );
   if( nGrid > 0 )
   {
      if( cx != 0 )
         bounds.OffsetRect( nGrid - ( ( bounds.left + 2 ) % nGrid ), 0 );
      if( cy != 0 )
         bounds.OffsetRect( 0, nGrid - ( ( bounds.top + 2 ) % nGrid ) );
   }
   MoveWindow( bounds );
   m_pFormOb->SetRect( bounds );
   ( (CVNSBView *)GetParent() )->GetDocument()->SetModifiedFlag();
} // DoMove

void CNSBFormObjectView::DoResize( int cx, int cy, int nDragHandle, int nGrid )
{
   CRect bounds;

   // Snap patch
   nGrid = -1;

   // Get our parent-relative bounds
   GetWindowRect( bounds );
   GetParent()->ScreenToClient( bounds );

   // Calculate our new rect and move window
   CPoint ptOrigin;
   CSize szDim;
   // Drag handle layout is like telephone keypad 1-9, with no 5
   switch( nDragHandle )
   {
   case 1: // Top-Left
      ptOrigin = CPoint( bounds.left + cx, bounds.top + cy );
      szDim    = CSize( bounds.Width() - cx, bounds.Height() - cy );
      if( ( nGrid > 0 ) && ( cx != 0 ) )
      {
         ptOrigin.Offset( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
         szDim -= CSize( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
      }
      if( ( nGrid > 0 ) && ( cy != 0 ) )
      {
         ptOrigin.Offset( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
         szDim -= CSize( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
      }
      break;
   case 2: // Top
      ptOrigin = CPoint( bounds.left, bounds.top + cy );
      szDim    = CSize( bounds.Width(), bounds.Height() - cy );
      if( ( nGrid > 0 ) && ( cy != 0 ) )
      {
         ptOrigin.Offset( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
         szDim -= CSize( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
      }
      break;
   case 3: // Top-Right
      ptOrigin = CPoint( bounds.left, bounds.top + cy );
      szDim    = CSize( bounds.Width() + cx, bounds.Height() - cy );
      if( ( nGrid > 0 ) && ( cx != 0 ) )
         szDim -= CSize( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
      if( ( nGrid > 0 ) && ( cy != 0 ) )
      {
         ptOrigin.Offset( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
         szDim -= CSize( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
      }
      break;
   case 4: // Left
      ptOrigin = CPoint( bounds.left + cx, bounds.top );
      szDim    = CSize( bounds.Width() - cx, bounds.Height() );
      if( ( nGrid > 0 ) && ( cx != 0 ) )
      {
         ptOrigin.Offset( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
         szDim -= CSize( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
      }
      break;
   case 6: // Right
      ptOrigin = CPoint( bounds.left, bounds.top );
      szDim    = CSize( bounds.Width() + cx, bounds.Height() );
      if( ( nGrid > 0 ) && ( cx != 0 ) )
         szDim -= CSize( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
      break;
   case 7: // Bottom-Left
      ptOrigin = CPoint( bounds.left + cx, bounds.top );
      szDim    = CSize( bounds.Width() - cx, bounds.Height() + cy );
      if( ( nGrid > 0 ) && ( cx != 0 ) )
      {
         ptOrigin.Offset( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
         szDim -= CSize( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
      }
      if( ( nGrid > 0 ) && ( cy != 0 ) )
         szDim -= CSize( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
      break;
   case 8: // Bottom
      ptOrigin = CPoint( bounds.left, bounds.top );
      szDim    = CSize( bounds.Width(), bounds.Height() + cy );
      if( ( nGrid > 0 ) && ( cy != 0 ) )
         szDim -= CSize( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
      break;
   case 9: // Bottom-Right
      ptOrigin = CPoint( bounds.left, bounds.top );
      szDim    = CSize( bounds.Width() + cx, bounds.Height() + cy );
      if( ( nGrid > 0 ) && ( cx != 0 ) )
         szDim -= CSize( nGrid - ( ( ptOrigin.x + 2 ) % nGrid ), 0 );
      if( ( nGrid > 0 ) && ( cy != 0 ) )
         szDim -= CSize( 0, nGrid - ( ( ptOrigin.y + 2 ) % nGrid ) );
      break;
   default:
      ASSERT( 0 );
   }
   // Don't allow window dimensions to go negative
   if( szDim.cx < 0 )
      szDim.cx = 0;
   if( szDim.cy < 0 )
      szDim.cy = 0;
   // Create new bounding rect
   bounds = CRect( ptOrigin, szDim );
   // Adjust m_ptClick, when expanding window size and relocating drag handles
   AdjustClickPoint( nDragHandle, bounds );
   MoveWindow( bounds );
   m_pFormOb->SetRect( bounds );
   ( (CVNSBView *)GetParent() )->GetDocument()->SetModifiedFlag();
} // DoResize

CNSBFormObject* CNSBFormObjectView::GetFormObject()
{
   return m_pFormOb;
} // GetFormObject

void CNSBFormObjectView::ChangeProperty( CString &strKey, CString strVal )
{
   INT nDim;
   CRect bounds = m_pFormOb->m_rectBounds;
   if( strKey == _T( "Left" ) )
   {
      _stscanf( strVal, _T( "%d" ), &nDim );
      bounds.OffsetRect( nDim - bounds.left, 0 );
      m_bRectChanged = TRUE;
   }
   if( strKey == _T( "Top" ) )
   {
      _stscanf( strVal, _T( "%d" ), &nDim );
      bounds.OffsetRect( 0, nDim - bounds.top );
      m_bRectChanged = TRUE;
   }
   if( strKey == _T( "Right" ) )
   {
      _stscanf( strVal, _T( "%d" ), &nDim );
      bounds.OffsetRect( nDim - bounds.right, 0 );
      m_bRectChanged = TRUE;
   }
   if( strKey == _T( "Bottom" ) )
   {
      _stscanf( strVal, _T( "%d" ), &nDim );
      bounds.OffsetRect( 0, nDim - bounds.bottom );
      m_bRectChanged = TRUE;
   }
   if( strKey == _T( "Width" ) )
   {
      _stscanf( strVal, _T( "%d" ), &nDim );
      bounds.DeflateRect( 0, 0, bounds.Width() - nDim, 0 );
      m_bRectChanged = TRUE;
   }
   if( strKey == _T( "Height" ) )
   {
      _stscanf( strVal, _T( "%d" ), &nDim );
      bounds.DeflateRect( 0, 0, 0, bounds.Height() - nDim );
      m_bRectChanged = TRUE;
   }
   if( m_bRectChanged )
   {
      m_bRectChanged = FALSE;
#ifdef _DEBUG
      afxDump << _T( "Key: " ) << strKey << _T( ", Val: " ) << strVal << _T( "\n" ); // #ifdef _DEBUG
      afxDump << _T( "  Form Rect: " ) << m_pFormOb->m_rectBounds << _T( "\n" ); // #ifdef _DEBUG
      afxDump << _T( "   New Rect: " ) << bounds << _T( "\n" ); // #ifdef _DEBUG
#endif
      bounds.InflateRect( 2, 2 );
      MoveWindow( bounds );
      m_pFormOb->SetRect( bounds );
   }
   else
      m_pFormOb->m_mapProperties[strKey] = strVal;
   ( (CVNSBView *)GetParent() )->GetDocument()->SetModifiedFlag();
} // ChangeProperty
