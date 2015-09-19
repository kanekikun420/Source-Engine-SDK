
struct RecvTable {
	RecvProp *m_pProps;
	int m_nProps;
	void *m_pDecoder;
	char *m_pNetTableName;
	char _padding[ 2 ];
};

struct RecvProp {
	char *m_pVarName;
	int m_RecvType;
	int m_Flags;
	int m_StringBufferSize;
	bool m_bInsideArray;
	const void *m_pExtraData;
	RecvProp *m_pArrayProp;
	void *m_ArrayLengthProxy;
	RecvVarProxyFn m_ProxyFn;
	void *m_DataTableProxyFn;
	RecvTable *m_pDataTable;
	int m_Offset;
	int m_ElementStride;
	int m_nElements;
	const char *m_pParentArrayPropName;
};

struct ClientClass {
	char _padding[ 8 ];
	char *m_pNetworkName;
	RecvTable *m_pRecvTable;
	ClientClass	*m_pNext;
	int m_ClassID;
};

class CClient
{
public:
  ClientClass* GetAllClasses()
  {
    typedef ClientClass*(__thiscall* fn)(void*);
    return ((fn)VMT.GetFunction(this, indexes::GetAllClasses))(this);
  }
};
