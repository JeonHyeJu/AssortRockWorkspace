#include "PreCompile.h"
#include "SoftRenderer.h"
#include "EngineAPICore.h"

USoftRenderer::USoftRenderer()
{
}

USoftRenderer::~USoftRenderer()
{
}

void USoftRenderer::BeginPlay()
{
	URenderer::BeginPlay();

	// ������ => ��׸�(360�й�)
	// ���Ȱ����� ����
	// 6.28
}

void USoftRenderer::Render(float _Delta)
{
	URenderer::Render(_Delta);

	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();
	UEngineWinImage* BackBufferImage = MainWindow.GetBackBuffer();
	HDC BackDC = BackBufferImage->GetDC();

	FTransform MainTrans = { {40, 40}, {300, 300} };

	{
		FVector LT = MainTrans.CenterLeftTop();
		FVector RB = MainTrans.CenterRightBottom();

		// Rectangle(BackDC, LT.iX(), LT.iY(), RB.iX(), RB	.iY() );
	}

	// 11��

	FTransform SubTrans = { {40, 40}, {0, 0} };

	// ȸ���ϴ� ���� 1
	
	//{
	//	// ������ ����� ȸ�� ȸ�� �⺻
	//	// 0,0 ���� + 300, 300�� �Ѱž�.
	//	SubTrans.Location += MainTrans.Location;
	//	Angle += _Delta;
	//	FVector DirVector = FVector::AngleToVectorRad(Angle);
	//	SubTrans.Location += DirVector * 100.0f;
	//	FVector LT = SubTrans.CenterLeftTop();
	//	FVector RB = SubTrans.CenterRightBottom();
	//	Rectangle(BackDC, LT.iX(), LT.iY(), RB.iX(), RB	.iY() );
	//}

	// ���� �׷���
	{
		//SinG.clear();

		//FVector StartPos = { 300, 300 };

		//for (size_t i = 0; i < 360; i++)
		//{
		//	float SinValue = cosf(static_cast<float>(i) * UEngineMath::D2R);
		//	FTransform ValueTrans = { { 30, 30 }, StartPos + FVector{ static_cast<float>(i * 2.0f),  SinValue * 100.0f } };
		//	SinG.push_back(ValueTrans);
		//}


		//// Ranged for
		//
		//// SinG.begin();
		//// SinG.end();

		//// �������� for
		//// ����� �����Ҷ� ��������.
		
		//for (FTransform& Trans : SinG)
		//{
		//	FVector LT = Trans.CenterLeftTop();
		//	FVector RB = Trans.CenterRightBottom();

		//	Rectangle(BackDC, LT.iX(), LT.iY(), RB.iX(), RB.iY());
		//}
		
	}


	{
		static float angles[6] = { 0.f, 90.f, 180.f, 0.f, 90.f, 180.f };

		FVector UpperPoint[3];
		FVector LowerPoint[3];

		FVector DirVector[6];

		for (int i = 0; i < 6; ++i)
		{
			angles[i] += _Delta;
			DirVector[i] = FVector::AngleToVectorRad(angles[i]);
		}

		UpperPoint[0] = FVector{200, 200} + DirVector[0] * 100.f;
		UpperPoint[1] = FVector{200, 200} + DirVector[1] * 100.f;
		UpperPoint[2] = FVector{200, 200} + DirVector[2] * 100.f;
		
		LowerPoint[0] = FVector{ 200, 200 } - DirVector[3] * 100.f;
		LowerPoint[1] = FVector{ 200, 200 } - DirVector[4] * 100.f;
		LowerPoint[2] = FVector{ 200, 200 } - DirVector[5] * 100.f;

		POINT UpperPt[3];
		POINT LowerPt[3];
		for (size_t i = 0; i < 3; i++)
		{
			UpperPt[i] = UpperPoint[i].ConvertWindowPOINT();
			LowerPt[i] = LowerPoint[i].ConvertWindowPOINT();
		}

		Polygon(BackDC, UpperPt, 3);
		Polygon(BackDC, LowerPt, 3);
	}
}