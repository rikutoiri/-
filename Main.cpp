#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"

//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
//	ChangeWindowMode(TRUE); //ウィンドウモード変更
//	DxLib_Init(); //DXライブラリ初期化
//	SetDrawScreen(DX_SCREEN_BACK); //裏画面設定
//	SceneMgr_Initialize(); //
//	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) { //画面更新 &メッセージ処理& 画面消去
//			SceneMgr_Update(); //更新
//		SceneMgr_Draw(); //描画
//	   // if (WaitKey()) break;
//	}
//	SceneMgr_Finalize();
//	DxLib_End(); // DXライブラリ終了処理
//	return 0;
//}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("テトリス");	//タイトルを設定
	ChangeWindowMode(TRUE);					//ウィンドウモード変更
	DxLib_Init();							//DXライブラリ初期化
	SetDrawScreen(DX_SCREEN_BACK);			//裏画面設定

	SceneMgr_Initialize(); //初期化

	while (ProcessMessage() == 0) { //メッセージ処理

		if (SceneMgr_GameEnd_Status()) {
			break;	//メニューから終了が選択された
		}

		ClearDrawScreen();	//画面消去

		InputKey();			//入力

		SceneMgr_Update();	//更新
		SceneMgr_Draw();	//描画

		ScreenFlip();		//画面更新

	}
	SceneMgr_Finalize();

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}