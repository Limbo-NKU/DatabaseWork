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

	//  isOnSale = 0;
}

DeleteDlg::~DeleteDlg()
{
}

void DeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_DELETEDLG_EDIT, sellerId);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_DELETEDLG_QUERY, &DeleteDlg::OnBnClickedDeletedlgQuery)
	ON_BN_CLICKED(IDOK, &DeleteDlg::OnBnClickedOk)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDCANCEL, &DeleteDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// DeleteDlg 消息处理程序


void DeleteDlg::OnBnClickedDeletedlgQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CListCtrl* lc = (CListCtrl*)GetDlgItem(IDC_DELETEDLG_SELLER);
	CString sql=
		L"select goods.*,seller_name,seller_phone from seller inner join goods on seller.seller_id = goods.seller_id where goods.seller_id =" 
		+ sellerId;
	//CDatabase db;
	//db.Open(L"MyDatabase");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, sql);
	DBtoListCtrl dblc(lc,&rs);
	dblc.GerenateLC();
	lc->ShowWindow(SW_SHOW);
	if (rs.GetRecordCount() > 0)
	{
		CButton* ok = (CButton*)GetDlgItem(IDOK);
		ok->EnableWindow();
	}
	sql = L"delete from goods where seller_id = " + sellerId;
	db.ExecuteSQL(sql);
	sql = L"delete from seller where seller_id = " + sellerId;
	db.ExecuteSQL(sql);
}


void DeleteDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	db.ExecuteSQL(L"commit tran tran_deleteSeller");
	CDialogEx::OnOK();

}


int DeleteDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	db.Open(L"MyDatabase");
	db.ExecuteSQL(L"begin tran tran_deleteSeller");

	return 0;
}


void DeleteDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	db.ExecuteSQL(L"rollback tran tran_deleteSeller");
	CDialogEx::OnCancel();
}
