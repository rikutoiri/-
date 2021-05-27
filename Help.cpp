#include "Help.h"
#include "SceneMgr.h"
#include "Dxlib.h"
#include "Input.h"

static int mImageHandle;	//�摜�n���h���i�[�p�ϐ�

//������
void Help_Initialize() {
	mImageHandle = LoadGraph("images/Help.png");	//�w�i�摜

}

//������
void Help_Finalize() {
	DeleteGraph(mImageHandle);	//�摜�̉��

}

//�I������
void Help_Update() {
	if (iKeyFlg == PAD_INPUT_2) {	//X�L�[�������ꂢ�Ă�����
		SceneMgr_ChangeScene(eScene_Menu);	//�V�[�����Q�[����ʂɕύX
	}
}

//�`��
void Help_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);

	SetFontSize(16);

	DrawString(150, 450, "---- X�������ă^�C�g���֖߂� ----", 0xffffff, 0);
}