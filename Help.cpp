#include "Help.h"
#include "SceneMgr.h"
#include "Dxlib.h"
#include "Input.h"

static int mImageHandle;	//画像ハンドル格納用変数

//初期化
void Help_Initialize() {
	mImageHandle = LoadGraph("images/Help.png");	//背景画像

}

//初期化
void Help_Finalize() {
	DeleteGraph(mImageHandle);	//画像の解放

}

//終了処理
void Help_Update() {
	if (iKeyFlg == PAD_INPUT_2) {	//Xキーが押されいていたら
		SceneMgr_ChangeScene(eScene_Menu);	//シーンをゲーム画面に変更
	}
}

//描画
void Help_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);

	SetFontSize(16);

	DrawString(150, 450, "---- Xを押してタイトルへ戻る ----", 0xffffff, 0);
}