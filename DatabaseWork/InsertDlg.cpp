// InsertDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "InsertDlg.h"
#include "afxdialogex.h"


// InsertDlg 对话框

IMPLEMENT_DYNAMIC(InsertDlg, CDialogEx)

InsertDlg::InsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERTDLG, pParent)
{

	goodsId = _T("");
	sellerId = _T("");
	goodsName = _T("");
	goodsPrice = _T("");
}

InsertDlg::~InsertDlg()
{
}

void InsertDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_INSERT_GOODSID, goodsId);
	DDX_Text(pDX, IDC_INSERT_SELLERID, sellerId);
	DDX_Text(pDX, IDC_INSERT_GOODSNAME, goodsName);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InsertDlg, CDialogEx)
	ON_BN_CLICKED(IDC_INSERTDLG_QUEST, &InsertDlg::OnBnClickedInsertdlgQuest)
END_MESSAGE_MAP()


// InsertDlg 消息处理程序


void InsertDlg::OnBnClickedInsertdlgQuest()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CMFCMaskedEdit *money = (CMFCMaskedEdit*)GetDlgItem(IDC_INSERT_GOODSPRICE);
	money->GetWindowText(goodsPrice);
	CString init, mask;
	init = goodsPrice.Left(6);
	mask = goodsPrice.Mid(6, 2);
	CString sql = L"";
	CDatabase db;
	db.Open(_T("MyDatabase"));
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, sql);
	if (rs.GetRecordCount() > 0)
	{
		MessageBox(L"更新成功！");
	}
	else
	{
		MessageBox(L"更新失败！");
	}

}
