/*
 * 3DES.h
 *
 *  Created on: 2017��9��29��
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
	// ���캯��
	CDesEncode();
	// ��������
	~CDesEncode();
	// ִ�м��ܡ����� ��ENCRYPT ���� DECRYPT ����
	void Des(char *src, char  *key, bool type, bool bIs3DES);
	char m_FCiphertextAnyLength[512];	//���ⳤ������
	char m_FPlaintextAnyLength[256];	//���ⳤ�������ַ���
private:
	/**
	 * 	����:����16��48λ��key
	 *	����:Դ8λ���ַ���(key),���key�����0-1
	 *	���:����������private CreateSubKey���������char SubKeys[keyN][16][48]
	 */
	void InitializeKey(char  *srcBytes, unsigned int keyN);
	/**
	 * 	����:����8λ�ַ���
	 *	����:8λ�ַ���,ʹ��Key�����0-1
	 *	���:���������ܺ��������private szCiphertext[16]
	 *	�û�ͨ������Ciphertext�õ�
	 */
	void EncryptData(char *_srcBytes, unsigned int keyN);
	/**
	 * 	����:����16λʮ�������ַ���
	 *	����:16λʮ�������ַ���,ʹ��Key�����0-1
	 *	���:���������ܺ��������private szPlaintext[8]
	 *	�û�ͨ������Plaintext�õ�
	 */
	void DecryptData(char *_srcBytes, unsigned int keyN);
	/**
	 * 	����:�������ⳤ���ַ���
	 *	����:���ⳤ���ַ���,����,ʹ��Key�����0-1
	 *	���:���������ܺ��������private szFCiphertextAnyLength[8192]
	 *	�û�ͨ������CiphertextAnyLength�õ�
	 */
	void EncryptAnyLength(char *_srcBytes, unsigned int _bytesLength, unsigned int keyN);
	/**
	 * 	����:�������ⳤ��ʮ�������ַ���
	 *	����:���ⳤ���ַ���,����,ʹ��Key�����0-1
	 *	���:���������ܺ��������private szFPlaintextAnyLength[8192]
	 *	�û�ͨ������PlaintextAnyLength�õ�
	 */
	void DecryptAnyLength(char *_srcBytes,unsigned int _bytesLength, unsigned int keyN);
	/**
	 * 	����:Bytes��Bits��ת��,
	 *	����:���任�ַ���,���������Ż�����ָ��,Bits��������С
	 */
	void Bytes2Bits(char *srcBytes, char *dstBits, unsigned int sizeBits);
	/**
	 *	����:Bits��Bytes��ת��,
	 *	����:���任�ַ���,���������Ż�����ָ��,Bits��������С
	 */
	void Bits2Bytes(char *dstBytes, char *srcBits, unsigned int sizeBits);
	/**
	 *	����:Int��Bits��ת��
	 *	����:���任�ַ���,���������Ż�����ָ��
	 */
	void Int2Bits(unsigned int srcByte, char *dstBits);
	/**
	 *	����:Bits��Hex��ת��
	 *	����:���任�ַ���,���������Ż�����ָ��,Bits��������С
	 */
	void Bits2Hex(char *dstHex, char *srcBits, unsigned int sizeBits);
	/**
	 *	����:Hex��Bits��ת��
	 *	����:���任�ַ���,���������Ż�����ָ��,Bits��������С
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
	char m_SubKeys[2][16][48];			//����2��16��48λ��Կ,��2������3DES
	char m_CiphertextRaw[64]; 			//�������������(64��Bits) int 0,1
	char m_PlaintextRaw[64]; 			//�������������(64��Bits) int 0,1
	char m_CiphertextInBytes[8];		//����8λ����
	char m_PlaintextInBytes[8];			//����8λ�����ַ���
	char m_CiphertextInBinary[65]; 		//�������������(64��Bits) char '0','1',���һλ��'\0'
	char m_CiphertextInHex[17]; 		//����ʮ����������,���һλ��'\0'
	char m_Plaintext[9];				//����8λ�����ַ���,���һλ��'\0'
	/**
	 *	����:��������Կ
	 *	����:����PC1�任��56λ�������ַ���,���ɵ�m_SubKeys���0-1
	 *	���:��������char m_SubKeys[16][48]
	 */
	void CreateSubKey(char *sz_56key, unsigned int keyN);
	/**
	 * 	����:DES�е�F����
	 * 	����:��32λ,��32λ,key���(0-15),ʹ�õ�m_SubKeys���0-1
	 * 	���:���ڱ任����32λ
	 */
	void FunctionF(char *sz_Li, char *sz_Ri, unsigned int iKey, unsigned int keyN);
	/**
	 *	����:IP�任
	 *	����:�������ַ���,����������ָ��
	 *	���:�����ı�ڶ�������������
	 */
	void InitialPermuteData(char *_src, char *_dst);
	/**
	 *  ����:����32λ������չλ48λ
	 *  ����:ԭ32λ�ַ���,��չ�������ָ��
	 *  ���:�����ı�ڶ�������������
	 */
	void ExpansionR(char *_src, char *_dst);
	/**
	 *  ����:�����
	 *  ����:�����Ĳ����ַ���1,�ַ���2,����������,����������ָ��
	 *  ���: �����ı���ĸ�����������
	 */
	void XOR(char *szParam1, char *szParam2, unsigned int uiParamLength, char *szReturnValueBuffer);
	/**
	 *  ����:S-BOX , ����ѹ��
	 *  ����:48λ�������ַ���
	 *  ���:���ؽ��:32λ�ַ���
	 */
	void CompressFuncS(char *_src48, char *_dst32);
	/**
	 * 	����:IP��任
	 *	����:���任�ַ���,����������ָ��
	 *	���:�����ı�ڶ�������������
	 */
	void PermutationP(char *_src, char *_dst);
};


#endif /* 3DES_H_ */
