/*
 * 3DES.h
 *
 *  Created on: 2017年9月29日
 *      Author: baoxd
 */

#ifndef THREE3DES_H_
#define THREE3DES_H_
#define ENCRYPT 0
#define DECRYPT 1
#pragma once
typedef char TCHAR ;
typedef unsigned int DWORD ;


class CDesEncode{
public:
	// 构造函数
	CDesEncode();
	// 析构函数
	~CDesEncode();
	// 执行加密、解密 ，ENCRYPT 加密 DECRYPT 解密
	void Des(char *src, char  *key, bool type, bool bIs3DES);
	char m_FCiphertextAnyLength[512];	//任意长度密文
	char m_FPlaintextAnyLength[256];	//任意长度明文字符串
private:
	/**
	 * 	功能:产生16个48位的key
	 *	参数:源8位的字符串(key),存放key的序号0-1
	 *	结果:函数将调用private CreateSubKey将结果存于char SubKeys[keyN][16][48]
	 */
	void InitializeKey(char  *srcBytes, unsigned int keyN);
	/**
	 * 	功能:加密8位字符串
	 *	参数:8位字符串,使用Key的序号0-1
	 *	结果:函数将加密后结果存放于private szCiphertext[16]
	 *	用户通过属性Ciphertext得到
	 */
	void EncryptData(char *_srcBytes, unsigned int keyN);
	/**
	 * 	功能:解密16位十六进制字符串
	 *	参数:16位十六进制字符串,使用Key的序号0-1
	 *	结果:函数将解密候结果存放于private szPlaintext[8]
	 *	用户通过属性Plaintext得到
	 */
	void DecryptData(char *_srcBytes, unsigned int keyN);
	/**
	 * 	功能:加密任意长度字符串
	 *	参数:任意长度字符串,长度,使用Key的序号0-1
	 *	结果:函数将加密后结果存放于private szFCiphertextAnyLength[8192]
	 *	用户通过属性CiphertextAnyLength得到
	 */
	void EncryptAnyLength(char *_srcBytes, unsigned int _bytesLength, unsigned int keyN);
	/**
	 * 	功能:解密任意长度十六进制字符串
	 *	参数:任意长度字符串,长度,使用Key的序号0-1
	 *	结果:函数将加密后结果存放于private szFPlaintextAnyLength[8192]
	 *	用户通过属性PlaintextAnyLength得到
	 */
	void DecryptAnyLength(char *_srcBytes,unsigned int _bytesLength, unsigned int keyN);
	/**
	 * 	功能:Bytes到Bits的转换,
	 *	参数:待变换字符串,处理后结果存放缓冲区指针,Bits缓冲区大小
	 */
	void Bytes2Bits(char *srcBytes, char *dstBits, unsigned int sizeBits);
	/**
	 *	功能:Bits到Bytes的转换,
	 *	参数:待变换字符串,处理后结果存放缓冲区指针,Bits缓冲区大小
	 */
	void Bits2Bytes(char *dstBytes, char *srcBits, unsigned int sizeBits);
	/**
	 *	功能:Int到Bits的转换
	 *	参数:待变换字符串,处理后结果存放缓冲区指针
	 */
	void Int2Bits(unsigned int srcByte, char *dstBits);
	/**
	 *	功能:Bits到Hex的转换
	 *	参数:待变换字符串,处理后结果存放缓冲区指针,Bits缓冲区大小
	 */
	void Bits2Hex(char *dstHex, char *srcBits, unsigned int sizeBits);
	/**
	 *	功能:Hex到Bits的转换
	 *	参数:待变换字符串,处理后结果存放缓冲区指针,Bits缓冲区大小
	 */
	void Hex2Bits(char *srcHex, char *dstBits, unsigned int sizeBits);
	char* GetCiphertextInBinary();
	char* GetCiphertextInHex();
	char* GetCiphertextInBytes();
	char* GetPlaintext();
	char* GetCiphertextAnyLength();
	char* GetPlaintextAnyLength();
	const static char IP_Table[64];
	const static char IPR_Table[64];
	const static char E_Table[48];
	const static char P_Table[32];
	const static char PC1_Table[56];
	const static char PC2_Table[48];
	const static char Shift_Table[16];
	const static char S_Box[8][4][16];
	char m_SubKeys[2][16][48];			//储存2个16组48位密钥,第2个用于3DES
	char m_CiphertextRaw[64]; 			//储存二进制密文(64个Bits) int 0,1
	char m_PlaintextRaw[64]; 			//储存二进制明文(64个Bits) int 0,1
	char m_CiphertextInBytes[8];		//储存8位密文
	char m_PlaintextInBytes[8];			//储存8位明文字符串
	char m_CiphertextInBinary[65]; 		//储存二进制密文(64个Bits) char '0','1',最后一位存'\0'
	char m_CiphertextInHex[17]; 		//储存十六进制密文,最后一位存'\0'
	char m_Plaintext[9];				//储存8位明文字符串,最后一位存'\0'
	/**
	 *	功能:生成子密钥
	 *	参数:经过PC1变换的56位二进制字符串,生成的m_SubKeys编号0-1
	 *	结果:将保存于char m_SubKeys[16][48]
	 */
	void CreateSubKey(char *sz_56key, unsigned int keyN);
	/**
	 * 	功能:DES中的F函数
	 * 	参数:左32位,右32位,key序号(0-15),使用的m_SubKeys编号0-1
	 * 	结果:均在变换左右32位
	 */
	void FunctionF(char *sz_Li, char *sz_Ri, unsigned int iKey, unsigned int keyN);
	/**
	 *	功能:IP变换
	 *	参数:待处理字符串,处理后结果存放指针
	 *	结果:函数改变第二个参数的内容
	 */
	void InitialPermuteData(char *_src, char *_dst);
	/**
	 *  功能:将右32位进行扩展位48位
	 *  参数:原32位字符串,扩展后结果存放指针
	 *  结果:函数改变第二个参数的内容
	 */
	void ExpansionR(char *_src, char *_dst);
	/**
	 *  功能:异或函数
	 *  参数:待异或的操作字符串1,字符串2,操作数长度,处理后结果存放指针
	 *  结果: 函数改变第四个参数的内容
	 */
	void XOR(char *szParam1, char *szParam2, unsigned int uiParamLength, char *szReturnValueBuffer);
	/**
	 *  功能:S-BOX , 数据压缩
	 *  参数:48位二进制字符串
	 *  结果:返回结果:32位字符串
	 */
	void CompressFuncS(char *_src48, char *_dst32);
	/**
	 * 	功能:IP逆变换
	 *	参数:待变换字符串,处理后结果存放指针
	 *	结果:函数改变第二个参数的内容
	 */
	void PermutationP(char *_src, char *_dst);
};


#endif /* 3DES_H_ */
