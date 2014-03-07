#include "compute_hash.h"
#include "C:\\openssl\\include\\openssl\\sha.h"

/*
int ComputeHash(char *filename, int size)	{
	HCRYPTPROV phProv;
	HCRYPTHASH *phHash = NULL;

	if(!CryptAcquireContext(&phProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))	{
		printf("CryptAcquireContext failed: %d", GetLastError());
		return -1;
	}

	if(!CryptCreateHash(&phProv, CALG_SHA_512, 0, 0, &phHash))	{
		printf("CryptCreateHash failed: %d", GetLastError());
		CryptReleaseContext(phProv, 0);
		return -1;
	}

	if(!CryptHashData(&phHash, data, strlen(data), CRYPT_OWF_REPL_LM_HASH))	{
		printf("CryptHashData failed: %d", GetLastError());
		CryptReleaseContext(phProv, 0);
		CryptDestroyHash(phHash);
		return -1;

	}

	if(!CryptGetHashParam(&phHash, HP_ALGID, data, &pbData ,0))	{
		printf("CryptGetHashParam failed: %d", GetLastError());
		CryptDestroyHash(phHash);
		CryptReleaseContext(hProv, 0);
	}

	return phHash;
}
*/

int ComputeHash()	{


}