#pragma once
#include <d3d11.h>
#include <wrl.h>
#include "Error.h"
#include <DirectXTex.h>

namespace wrl = Microsoft::WRL;
class Texture
{
public:
	ID3D11ShaderResourceView* GetShaderResourceView() const;
	ID3D11ShaderResourceView** GetShaderResourceViewAddress();
	std::string GetPath() const noexcept;
	std::string GetDirectory() const noexcept;
	void Bind(ID3D11DeviceContext* pContext);
	Texture() = default;
	Texture(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, const std::string& filepath, unsigned int slot = 0);
private:
	wrl::ComPtr<ID3D11ShaderResourceView> m_view;
	wrl::ComPtr<ID3D11Resource> m_resource;
private:
	unsigned int slot;
	std::string path;
};