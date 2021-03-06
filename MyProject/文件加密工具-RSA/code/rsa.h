#pragma once
#include <string>
#include "BigInt.h"

namespace lb
{
	//typedef long rsaDataType;
	typedef BigInt rsaDataType;
	constexpr int DEBUG = 0;
	constexpr int BUFFERSIZE = 256;

	struct RsaKey
	{
		rsaDataType m_eKey;
		rsaDataType m_dKey;
		rsaDataType m_pKey;
	};

	class Rsa
	{
	private:
		RsaKey m_key;

	private:
		static bool isPrime(rsaDataType num);
		static rsaDataType getRandom();
		static rsaDataType getPrime();
		static rsaDataType getPKey(rsaDataType prime1, rsaDataType prime2);
		static rsaDataType getOrla(rsaDataType prime1, rsaDataType prime2);
		static rsaDataType getEKey(rsaDataType orla);
		static rsaDataType getDKey(rsaDataType eKey, rsaDataType orla);
		static rsaDataType extendGcd(rsaDataType a, rsaDataType b, rsaDataType & x, rsaDataType & y);
		static rsaDataType getGcd(rsaDataType num1, rsaDataType num2);
		rsaDataType dealData(rsaDataType data, rsaDataType e, rsaDataType n);

	public:
		Rsa();
		Rsa(const RsaKey & key);
		
		static RsaKey getRsaKey();
		rsaDataType ecrept(rsaDataType data);
		rsaDataType ecrept(rsaDataType data, rsaDataType eKey, rsaDataType pKey);
		rsaDataType decrept(rsaDataType data);
		rsaDataType decrept(rsaDataType data, rsaDataType dKey, rsaDataType pKey);
		bool ecreptFile(const std::string filename, const std::string e_filename);
		bool decreptFile(const std::string e_filename, const std::string d_filename);

		void show() const;
	};
}