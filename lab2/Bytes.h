#pragma once

#include "Bin.h"
#include "Oct.h"
#include "Hex.h"


union Bytes
{
private:
	Bin m_bin;
	Oct m_oct;
	Hex m_hex;
	unsigned char m_dec;
public:

	

	Bytes(unsigned char byte) { m_dec = byte; } //конструктор

	void ShowBin() { m_bin.Show(); }
	void ShowHex() { m_hex.intShow(); }
	void ShowOct() { m_oct.intShow(); }

	void ShowDec() { std::cout << static_cast<int>(m_dec)<<std::endl; }
	void ShowChar() { std::cout << m_dec << std::endl; }

	void ShowBinPos(int pos) { m_bin.ShowPos(pos); }
	void ShowOctPos(int pos) { m_oct.intShowPos(pos); }
	void ShowHexPos(int pos) { m_hex.intShowPos(pos); }


	void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
	void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
	void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
};