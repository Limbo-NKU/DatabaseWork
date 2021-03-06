// InsertDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "InsertDlg.h"
#include "afxdialogex.h"
#include "DBtoListCtrl.h"


// InsertDlg 对话框

IMPLEMENT_DYNAMIC(InsertDlg, CDialogEx)

InsertDlg::InsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERTDLG, pParent)
{

	goodsId = _T("");
	sellerId = _T("");
	goodsName = _T("");
	goodsPrice = _T("");
	isOnSale = 0;
}

InsertDlg::~InsertDlg()
{
}

void InsertDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Check(pDX, IDC_INSERT_ONSALE, isOnSale);
	DDX_Text(pDX, IDC_INSERT_GOODSID, goodsId);
	DDX_Text(pDX, IDC_INSERT_SELLERID, sellerId);
	DDX_Text(pDX, IDC_INSERT_GOODSNAME, goodsName);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InsertDlg, CDialogEx)
	ON_BN_CLICKED(IDC_INSERTDLG_QUEST, &InsertDlg::OnBnClickedInsertdlgQuest)
//	ON_WM_CREATE()
END_MESSAGE_MAP()


// InsertDlg 消息处理程序


void InsertDlg::OnBnClickedInsertdlgQuest()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CMFCMaskedEdit *money = (CMFCMaskedEdit*)GetDlgItem(IDC_INSERT_GOODSPRICE);
	money->GetWindowText(goodsPrice);
	CString init, mask,str_isOnSale;
	init = goodsPrice.Left(6);
	mask = goodsPrice.Mid(6, 2);
	str_isOnSale.Format(L"%d", isOnSale);
	if (goodsName == L"")
	{
		goodsName = L"null";
	}
	else
	{
		goodsName = L"'" + goodsName + L"'";
	}
	CString sql = L"INSERT goods VALUES ("
		+goodsId+L","
		+sellerId+L","
		+goodsName+L","
		+init+L"."+mask+","
		+str_isOnSale
		+L")";
	CDatabase db;
	db.Open(_T("MyDatabase"));
	try
	{
		db.ExecuteSQL(sql);
	}
	catch (CDBException* pe)
	{
		// The error code is in pe->m_nRetCode
		pe->ReportError();
		//pe->Delete();
	}
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, L"select * from goods where goods_id = " + goodsId);
	CListCtrl *lc = (CListCtrl*)GetDlgItem(IDC_INSERT_LIST);
	DBtoListCtrl dblc(lc, &rs);
	dblc.GerenateLC();
	lc->ShowWindow(SW_SHOW);
	/*
	if (rs.GetRecordCount() > 0)
	{
	MessageBox(L"更新成功！");
	}
	else
	{
	MessageBox(L"更新失败！");
	}

	*/

}


//int InsertDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  在此添加您专用的创建代码
//
//	return 0;
//}
