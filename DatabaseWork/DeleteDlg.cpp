// DeleteDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"
#include "DBtoListCtrl.h"

// DeleteDlg 对话框

IMPLEMENT_DYNAMIC(DeleteDlg, CDialogEx)

DeleteDlg::DeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETEDLG, pParent)
	, sellerId(_T(""))
{

}

DeleteDlg::~DeleteDlg()
{
}

void DeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_DELETEDLG_QUERY, &DeleteDlg::OnBnClickedDeletedlgQuery)
	ON_BN_CLICKED(IDOK, &DeleteDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// DeleteDlg 消息处理程序


void DeleteDlg::OnBnClickedDeletedlgQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CListCtrl* lc = (CListCtrl*)GetDlgItem(IDC_DELETEDLG_EDIT);
	CString sql=L"SELECT * FROM goods WHERE sellerId = " + sellerId;
	CDatabase db;
	db.Open(L"MyDatabase");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, sql);
	DBtoListCtrl dblc(lc,&rs);
	dblc.GerenateLC();
	if (rs.GetRecordCount() > 0)
	{
		CButton* ok = (CButton*)GetDlgItem(IDOK);
		ok->EnableWindow();
	}
}


void DeleteDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

}
