#include <Novice.h>
#include <math.h>

const char kWindowTitle[] = "GC2A_12_スズキ_イヲリ";

struct Vector3 {
	float x, y, z;
};

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
//減算
Vector3 Substract(const Vector3& v1, const Vector3& v2);
//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);
//内積
float Dot(const Vector3& v1, const Vector3& v2);
//ノルム
float Length(const Vector3& v);
//正規化
Vector3 Normalize(const Vector3& v);

void Vector3ScreenPrint(int x, int y, const Vector3& v, const char label[]);

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 v1 = { 4.0f,-2.0f,6.0f };
	Vector3 v2 = { 3.0f,5.0f,-3.0f };
	float scalar = 4.0f;

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubstract = Substract(v1, v2);
	Vector3 resultMultiply = Multiply(scalar, v1);
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Vector3ScreenPrint(0, 0, resultAdd, "Add");
		Vector3ScreenPrint(0, 20, resultSubstract, "Substract");
		Vector3ScreenPrint(0, 40, resultMultiply, "Multiply");
		Novice::ScreenPrintf(0, 60, "%6.2f : Dot", resultDot);
		Novice::ScreenPrintf(0, 80, "%6.2f : Length", resultLength);
		Vector3ScreenPrint(0, 100, resultNormalize, "Normalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}


Vector3 Add(const Vector3& v1, const Vector3& v2) {

	return { v1.x + v2.x,v1.y + v2.y, v1.z + v2.z };

}
Vector3 Substract(const Vector3& v1, const Vector3& v2) {

	return { v1.x - v2.x,v1.y - v2.y, v1.z - v2.z };

}
Vector3 Multiply(float scalar, const Vector3& v) {

	return { v.x * scalar ,v.y * scalar , v.z * scalar };

}
float Dot(const Vector3& v1, const Vector3& v2) {

	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

}
float Length(const Vector3& v) {

	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

}
Vector3 Normalize(const Vector3& v) {

	float length = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	return{ (v.x / length),	(v.y / length),	(v.z / length) };

}

void Vector3ScreenPrint(int x, int y, const Vector3& v, const char label[]) {

	Novice::ScreenPrintf(x, y, "%6.2f %6.2f %6.2f : %s", v.x, v.y, v.z, label);

}