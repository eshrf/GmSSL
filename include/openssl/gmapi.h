/* ====================================================================
 * Copyright (c) 2015 - 2016 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 */

#ifndef HEADER_GMAPI_H
#define HEADER_GMAPI_H
#ifndef NO_GMSSL

#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/cmac.h>
#include <openssl/cbcmac.h>
#include <openssl/skf.h>
#include <openssl/sdf.h>

#ifdef __cplusplus
extern "C" {
#endif

int SKF_print_dev_info(DEVINFO *devInfo);
char *SKF_get_alg_name(ULONG ulAlgID);
char *SKF_get_errstr(ULONG ulError);
int SKF_nid_to_encparams(int nid, ULONG *algID, BLOCKCIPHERPARAM *params);

RSA *RSA_new_from_RSAPUBLICKEYBLOB(const RSAPUBLICKEYBLOB *blob);
RSA *RSA_new_from_RSAPRIVATEKEYBLOB(const RSAPRIVATEKEYBLOB *blob);
int RSA_set_RSAPUBLICKEYBLOB(RSA *rsa, const RSAPUBLICKEYBLOB *blob);
int RSA_get_RSAPUBLICKEYBLOB(RSA *rsa, RSAPUBLICKEYBLOB *blob);
int RSA_set_RSAPRIVATEKEYBLOB(RSA *rsa, const RSAPRIVATEKEYBLOB *blob);
int RSA_get_RSAPRIVATEKEYBLOB(RSA *rsa, RSAPRIVATEKEYBLOB *blob);

ULONG DEVAPI SKF_GenExtECCKeyPair(DEVHANDLE hDev,
	ECCPRIVATEKEYBLOB *priKey,
	ECCPUBLICKEYBLOB *pubKey);

EC_KEY *EC_KEY_new_from_ECCPUBLICKEYBLOB(const ECCPUBLICKEYBLOB *blob);
EC_KEY *EC_KEY_new_from_ECCPRIVATEKEYBLOB(const ECCPRIVATEKEYBLOB *blob);
int EC_KEY_set_ECCPUBLICKEYBLOB(EC_KEY *ec_key, const ECCPUBLICKEYBLOB *blob);
int EC_KEY_get_ECCPUBLICKEYBLOB(EC_KEY *ec_key, ECCPUBLICKEYBLOB *blob);
int EC_KEY_set_ECCPRIVATEKEYBLOB(EC_KEY *ec_key, const ECCPRIVATEKEYBLOB *blob);
int EC_KEY_get_ECCPRIVATEKEYBLOB(EC_KEY *ec_key, ECCPRIVATEKEYBLOB *blob);

SM2_CIPHERTEXT_VALUE *SM2_CIPHERTEXT_VALUE_new_from_ECCCIPHERBLOB(const ECCCIPHERBLOB *blob);
int SM2_CIPHERTEXT_VALUE_set_ECCCIPHERBLOB(SM2_CIPHERTEXT_VALUE *cv, const ECCCIPHERBLOB *blob);
int SM2_CIPHERTEXT_VALUE_get_ECCCIPHERBLOB(const SM2_CIPHERTEXT_VALUE *cv, ECCCIPHERBLOB *blob);

ECDSA_SIG *ECDSA_SIG_new_from_ECCSIGNATUREBLOB(const ECCSIGNATUREBLOB *blob);
int ECDSA_SIG_get_ECCSIGNATUREBLOB(const ECDSA_SIG *sig, ECCSIGNATUREBLOB *blob);
int ECDSA_SIG_set_ECCSIGNATUREBLOB(ECDSA_SIG *sig, const ECCSIGNATUREBLOB *blob);


/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */

int ERR_load_GMAPI_strings(void);

/* Error codes for the GMAPI functions. */

/* Function codes. */
# define GMAPI_F_ECDSA_SIG_GET_ECCSIGNATUREBLOB           100
# define GMAPI_F_ECDSA_SIG_NEW_FROM_ECCSIGNATUREBLOB      101
# define GMAPI_F_ECDSA_SIG_SET_ECCSIGNATUREBLOB           102
# define GMAPI_F_EC_KEY_GET_ECCPRIVATEKEYBLOB             103
# define GMAPI_F_EC_KEY_GET_ECCPUBLICKEYBLOB              104
# define GMAPI_F_EC_KEY_NEW_FROM_ECCPRIVATEKEYBLOB        105
# define GMAPI_F_EC_KEY_NEW_FROM_ECCPUBLICKEYBLOB         106
# define GMAPI_F_EC_KEY_SET_ECCPRIVATEKEYBLOB             107
# define GMAPI_F_EC_KEY_SET_ECCPUBLICKEYBLOB              108
# define GMAPI_F_RSA_GET_RSAPRIVATEKEYBLOB                123
# define GMAPI_F_RSA_GET_RSAPUBLICKEYBLOB                 124
# define GMAPI_F_RSA_NEW_FROM_RSAPRIVATEKEYBLOB           125
# define GMAPI_F_RSA_NEW_FROM_RSAPUBLICKEYBLOB            126
# define GMAPI_F_RSA_SET_RSAPRIVATEKEYBLOB                127
# define GMAPI_F_RSA_SET_RSAPUBLICKEYBLOB                 128
# define GMAPI_F_SKF_CLOSEHANDLE                          109
# define GMAPI_F_SKF_EXTECCDECRYPT                        110
# define GMAPI_F_SKF_EXTECCENCRYPT                        111
# define GMAPI_F_SKF_EXTECCSIGN                           112
# define GMAPI_F_SKF_EXTECCVERIFY                         113
# define GMAPI_F_SKF_EXTRSAPRIKEYOPERATION                129
# define GMAPI_F_SKF_EXTRSAPUBKEYOPERATION                130
# define GMAPI_F_SKF_GENEXTECCKEYPAIR                     114
# define GMAPI_F_SKF_GENEXTRSAKEY                         131
# define GMAPI_F_SKF_HANDLE_GET_CBCMAC_CTX                115
# define GMAPI_F_SKF_HANDLE_GET_CIPHER                    116
# define GMAPI_F_SKF_HANDLE_GET_CIPHER_CTX                117
# define GMAPI_F_SKF_HANDLE_GET_KEY                       118
# define GMAPI_F_SKF_HANDLE_GET_MD_CTX                    119
# define GMAPI_F_SM2_CIPHERTEXT_VALUE_GET_ECCCIPHERBLOB   120
# define GMAPI_F_SM2_CIPHERTEXT_VALUE_NEW_FROM_ECCCIPHERBLOB 121
# define GMAPI_F_SM2_CIPHERTEXT_VALUE_SET_ECCCIPHERBLOB   122

/* Reason codes. */
# define GMAPI_R_BUFFER_TOO_SMALL                         135
# define GMAPI_R_CTX_NOT_CREATED                          100
# define GMAPI_R_DECODE_EC_PRIVATE_KEY_FAILED             101
# define GMAPI_R_DECODE_EC_PUBLIC_KEY_FAILED              102
# define GMAPI_R_DECRYPT_FAILED                           103
# define GMAPI_R_ENCODE_CIPHERTEXT_FAILED                 104
# define GMAPI_R_ENCODE_FAILED                            136
# define GMAPI_R_ENCODE_RSA_PUBLIC_KEY_FAILED             137
# define GMAPI_R_ENCODE_SIGNATURE_FAILED                  105
# define GMAPI_R_ENCRYPT_FAILED                           106
# define GMAPI_R_GEN_RSA_FAILED                           138
# define GMAPI_R_GET_PRIVATE_KEY_FAILED                   107
# define GMAPI_R_GET_PUBLIC_KEY_FAILED                    108
# define GMAPI_R_INVALID_ALGOR                            109
# define GMAPI_R_INVALID_BIGNUM_LENGTH                    110
# define GMAPI_R_INVALID_CIPHERTEXT                       111
# define GMAPI_R_INVALID_CIPHERTEXT_LENGTH                112
# define GMAPI_R_INVALID_CIPHERTEXT_MAC                   113
# define GMAPI_R_INVALID_CIPHERTEXT_POINT                 114
# define GMAPI_R_INVALID_DIGEST_LENGTH                    115
# define GMAPI_R_INVALID_ECC_PRIVATE_KEY                  116
# define GMAPI_R_INVALID_ECC_PUBLIC_KEY                   117
# define GMAPI_R_INVALID_EC_KEY                           118
# define GMAPI_R_INVALID_EC_PRIVATE_KEY                   119
# define GMAPI_R_INVALID_EC_PUBLIC_KEY                    120
# define GMAPI_R_INVALID_FEED_BIT_LENGTH                  121
# define GMAPI_R_INVALID_HANDLE_ALGOR                     122
# define GMAPI_R_INVALID_HANDLE_MAGIC                     123
# define GMAPI_R_INVALID_HANDLE_TYPE                      124
# define GMAPI_R_INVALID_INPUT_LENGTH                     139
# define GMAPI_R_INVALID_KEY_HANDLE                       125
# define GMAPI_R_INVALID_KEY_LENGTH                       126
# define GMAPI_R_INVALID_PLAINTEXT_LENGTH                 127
# define GMAPI_R_INVALID_PRIVATE_KEY                      128
# define GMAPI_R_INVALID_PUBLIC_KEY                       129
# define GMAPI_R_INVALID_RSA_KEY_LENGTH                   140
# define GMAPI_R_INVALID_RSA_PRIVATE_KEY                  141
# define GMAPI_R_INVALID_RSA_PUBLIC_KEY                   142
# define GMAPI_R_INVALID_SIGNATURE                        130
# define GMAPI_R_MALLOC_FAILED                            131
# define GMAPI_R_NULL_ARGUMENT                            132
# define GMAPI_R_SIGN_FAILED                              133
# define GMAPI_R_VERIFY_NOT_PASS                          134

#  ifdef  __cplusplus
}
#  endif
# endif
#endif
