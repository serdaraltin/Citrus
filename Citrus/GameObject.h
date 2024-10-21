#pragma once
#include "GfxBase.h"
#include "DepthBuffer.h"
#include "Wireframe.h"
#include "Fog.h"

class GameObject
{
private:
	struct matrices
	{
		XMFLOAT3 camera_pos;
		float pad;
	};
public:
	GameObject() = default;
	GameObject(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, std::string filepath, int width, int height, bool hasMaterial);
	GameObject(const GameObject&) {}
	bool HasNormal() const;
	static bool* GetDepthBufferEnabled();
	static bool* GetBlurEnabled();
	static bool* GetWireframeEnabled();
	static bool* GetFogEnabled();
	static bool* GetBackCulling();
	static bool* GetFrontCulling();
	static XMFLOAT3* GetWireColor();
	static XMFLOAT4* GetFogColor();
	static float* GetFogStart();
	static float* GetFogEnd();
	static bool SetDepthBufferEnabled(bool value);
	static bool SetFogEnabled(bool value);
	static bool SetWireframeEnabled(bool value);
	static bool SetFrontCull(bool value);
	static bool SetBackCull(bool value);
	static float SetFogStart(float value);
	static float SetFogEnd(float value);
	std::string GetName() const;
	bool& GetIsDestroyed() const;
	void draw(Camera3D cam);
	void Destroy() const noexcept;
	Model* GetMesh();
	~GameObject()=default;
private:
	Model pModel;
	VertexShader pVSNormal;
	VertexShader pVS;
	VertexShader pVSEmessive;
	VertexShader pVSLit;
	VertexShader pVSParallax;
	PixelShader pPS;
	PixelShader pPSNormal;
	PixelShader pPSEmessive;
	PixelShader pPSLit;
	PixelShader pPSParallax;
private:
	ID3D11Device* pDevice;
	ID3D11DeviceContext* pContext;
	std::unique_ptr<InputLayout> pLayoutNormal;
	std::unique_ptr<InputLayout> pLayout;
	std::unique_ptr<InputLayout> pLayoutLit;
	std::unique_ptr<CBuffer<matrices>> matrices_buffer;
	std::unique_ptr<UI> ui;
	Microsoft::WRL::ComPtr<ID3D11SamplerState> st;
	Microsoft::WRL::ComPtr<ID3D11SamplerState> ssam;
	Microsoft::WRL::ComPtr<ID3D11SamplerState> pcfSam;
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> pRasterizer = nullptr;
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> pRasterizerBack = nullptr;
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> pRasterizerFront = nullptr;
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> pRasterizerWireframe = nullptr;
	std::string directory;
	bool isRendered = false;
	mutable bool isDestroyed = false;
	DepthBuffer pDepthBuffer;
	Wireframe pWireframe;
	Fog pFog;
	int width;
	int height;
};

