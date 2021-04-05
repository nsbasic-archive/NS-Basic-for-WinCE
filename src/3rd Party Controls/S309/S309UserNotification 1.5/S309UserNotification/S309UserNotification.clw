; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CS309UserNotificationCtrl
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "s309usernotification.h"
LastPage=0
CDK=Y

ClassCount=5
Class1=CS309Alert
Class2=CS309Alerts
Class3=CS309Icon
Class4=CS309UserNotificationCtrl
Class5=CS309UserNotificationPropPage

ResourceCount=2
Resource1=IDD_ABOUTBOX_S309USERNOTIFICATION
Resource2=IDD_PROPPAGE_S309USERNOTIFICATION

[CLS:CS309Alert]
Type=0
BaseClass=CWnd
HeaderFile=S309Alert.h
ImplementationFile=S309Alert.cpp

[CLS:CS309Alerts]
Type=0
BaseClass=CWnd
HeaderFile=S309Alerts.h
ImplementationFile=S309Alerts.cpp

[CLS:CS309Icon]
Type=0
BaseClass=CCmdTarget
HeaderFile=S309Icon.h
ImplementationFile=S309Icon.cpp
Filter=N
VirtualFilter=C

[CLS:CS309UserNotificationCtrl]
Type=0
BaseClass=COleControl
HeaderFile=S309UserNotificationCtl.h
ImplementationFile=S309UserNotificationCtl.cpp

[CLS:CS309UserNotificationPropPage]
Type=0
BaseClass=COlePropertyPage
HeaderFile=S309UserNotificationPpg.h
ImplementationFile=S309UserNotificationPpg.cpp

[DLG:IDD_PROPPAGE_S309USERNOTIFICATION]
Type=1
Class=CS309UserNotificationPropPage
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX_S309USERNOTIFICATION]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

