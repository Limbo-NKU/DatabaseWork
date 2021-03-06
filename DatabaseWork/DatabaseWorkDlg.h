
// DatabaseWorkDlg.h: 头文件
//

#pragma once


// CDatabaseWorkDlg 对话框
class CDatabaseWorkDlg : public CDialogEx
{
// 构造
public:
	CDatabaseWorkDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATABASEWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedInsert();
	afx_msg void OnBnClickedDelete();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
