#pragma once


// UpdateDlg 对话框

class UpdateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UpdateDlg)

public:
	UpdateDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~UpdateDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString goodsId;
	CString sellerId;
	CString goodsName;
	CString goodsPrice;
	//CString goodsPriceMasked;
	afx_msg void OnBnClickedUpdatedlgQuest();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	int isOnSale;
};
