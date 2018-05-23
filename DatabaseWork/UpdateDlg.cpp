// UpdateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "UpdateDlg.h"
#include "afxdialogex.h"


// UpdateDlg 对话框

IMPLEMENT_DYNAMIC(UpdateDlg, CDialogEx)

UpdateDlg::UpdateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATEDLG, pParent)
	
{
	goodsId = _T("");
	sellerId = _T("");
	goodsName = _T("");
	goodsPrice = _T("");
}

UpdateDlg::~UpdateDlg()
{
}

void UpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX,IDC_UPDATE_GOODSID,goodsId);
	DDX_Text(pDX, IDC_UPDATE_SELLERID, sellerId);
	DDX_Text(pDX, IDC_UPDATE_GOODSNAME, goodsName);
	//DDX_Text(pDX, IDC_UPDATE_GOODSPRICE, goodsPrice);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpdateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_UPDATEDLG_QUEST, &UpdateDlg::OnBnClickedUpdatedlgQuest)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// UpdateDlg 消息处理程序


void UpdateDlg::OnBnClickedUpdatedlgQuest()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CMFCMaskedEdit *money = (CMFCMaskedEdit*)GetDlgItem(IDC_UPDATE_GOODSPRICE);
	money->GetWindowText(goodsPrice);
	CString init,mask;
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

int UpdateDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//CMFCMaskedEdit *money = (CMFCMaskedEdit*)GetDlgItem(IDC_UPDATE_GOODSPRICE);
	return 0;
}
