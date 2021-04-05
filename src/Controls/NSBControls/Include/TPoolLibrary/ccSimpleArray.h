#ifndef _TPOOLLIBRARY_OBJARRAY_H_
#define _TPOOLLIBRARY_OBJARRAY_H_

// #include <stddef.h>
#include <malloc.h>
#include <string.h>

template <class T> class ccSimpleArray
{
protected:
	T* m_Data;
	int m_nSize, m_nAllocated, m_nDelta;
public:
	ccSimpleArray():    m_Data(NULL), 
                        m_nSize(0), 
                        m_nAllocated(0), 
                        m_nDelta(1) {}
	ccSimpleArray(ccSimpleArray<T>& src):   m_Data(NULL), 
                                            m_nSize(0), 
                                            m_nAllocated(0), 
                                            m_nDelta(1)	{
		if (m_nSize > 0) RemoveAll();
		
		m_nSize = src.m_nSize;
		m_nAllocated = src.m_nAllocated;
		m_nDelta = src.m_nDelta;

		m_Data = (T*)malloc(m_nAllocated * sizeof(T));
		memcpy((void*)m_Data, (void*)src.m_Data, m_nSize * sizeof(T));
	}
	
	~ccSimpleArray() {
		RemoveAll();
	}
	inline int GetSize() {return m_nSize;}
	inline T* GetData() {return m_Data;}
	inline void SetDelta(int newDelta) {
		if(newDelta > 0) m_nDelta = newDelta;
	}
	inline int GetDelta() {return m_nDelta;}

	bool Add(T& obj)	{
        if(m_nSize == m_nAllocated)	{ // Realocation needed
			T* newData;
			int newAllocated = m_nAllocated + m_nDelta;

			newData = (T*)realloc((void*)m_Data, newAllocated * sizeof(T));
			if(!newData) return false;
			m_nAllocated = newAllocated;
			m_Data = newData;
		}
		m_nSize++;
		SetAtIndex(m_nSize-1, obj);
		return true;
	}

	void RemoveAll() {
		if (!m_Data) return;
		for (int i = 0; i < m_nSize; i++) m_Data[i].~T();
		free(m_Data);
		m_Data = NULL; m_nSize = 0; m_nAllocated = 0;
	}
	inline T& operator[](int Index)	{
		return m_Data[Index];
	}

	class __CVoid {
	    public:
		    __CVoid(T& v):_t(v){}
		    void* operator new(size_t, void* p){return p;}
		    void operator delete(void *, void *){}
		T _t;
	};
	void SetAtIndex(int Index, T& obj) {
		new(m_Data + Index) __CVoid(obj);
	}
	bool Insert(T& obj, int Index) {
        if(m_nSize == m_nAllocated)	{ // Realocation needed
			T* newData;
			int newAllocated = m_nAllocated + m_nDelta;

			newData = (T*)realloc(m_Data, newAllocated * sizeof(T));
			if(!newData) return false;
			m_nAllocated = newAllocated;
			m_Data = newData;
		}

		if (m_nSize > 0)
			memmove((void*)(m_Data + Index + 1),(void*)(m_Data + Index), (m_nSize - Index) * sizeof(T));
		m_nSize++;
		SetAtIndex(Index, obj);	
        return true;
	}
	
	void RemoveAt(int Index) {
		m_Data[Index].~T();
		if(Index < m_nSize-1)
			memmove((void*)(m_Data + Index), (void*)(m_Data + Index + 1), (m_nSize - (Index + 1)) * sizeof(T));
		m_nSize--;
		if (m_nSize == 0) return;

        if ((m_nAllocated - m_nSize) >= m_nDelta) {// Memory should be freed
			T* newData;
			int newAllocated = m_nAllocated - m_nDelta;

			newData = (T*)realloc(m_Data, newAllocated * sizeof(T));
			if (!newData) return;
			m_Data = newData;
			m_nAllocated = newAllocated;
		}
	}

	bool Remove(T& obj)	{
		int index = Find(obj);
		if(index != -1)
		{
			Remove(index);
			return true;
		}
		return false;
	}

	int Find(T& obj) {
		for(int i = 0; i < m_nSize; i++)
			if(obj == m_Data[i]) return i;
		return -1;
	}

	ccSimpleArray<T>& operator= (ccSimpleArray<T>& src)	{
		if (m_nSize > 0) RemoveAll();
		
		m_nSize = src.m_nSize;
		m_nAllocated = src.m_nAllocated;
		m_nDelta = src.m_nDelta;

		m_Data = (T*)malloc(m_nAllocated * sizeof(T));
		memcpy((void*)m_Data, (void*)src.m_Data, m_nSize * sizeof(T));
		return *this;
	}
};


template <class T> class ccSimpleStackArray : public ccSimpleArray<T>
{
public:
	ccSimpleStackArray(){}
	~ccSimpleStackArray() {}

	int PushConst(const T obj)
	{
		T& _obj = (T&)obj;
		return Add(_obj);
	}
	int Push(T& obj)
	{
		return Add(obj);
	}

	T Pop()
	{
		T obj;
		
		if(m_nSize > 0)
		{
			obj = m_Data[m_nSize-1];
			Remove(m_nSize-1);
			if(m_nSize == 0) Clear();
		}
		else
			memset((void*)&obj, NULL, sizeof(T));
		return obj;
	}

	inline bool IsEOF() {return (m_nSize <= 0);}
	inline int  Depth() { return m_nSize; }
};

#endif _TPOOLLIBRARY_OBJARRAY_H_