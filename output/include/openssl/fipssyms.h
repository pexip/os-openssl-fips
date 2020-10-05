
/* Where necessary redirect standard OpenSSL APIs to FIPS versions */

#define CRYPTO_lock FIPS_lock
#define CRYPTO_add_lock FIPS_add_lock
#define CRYPTO_malloc FIPS_malloc
#define CRYPTO_free FIPS_free

#define ERR_put_error FIPS_put_error
#define ERR_add_error_data FIPS_add_error_data

#define EVP_MD_CTX_init FIPS_md_ctx_init
#define EVP_MD_CTX_cleanup FIPS_md_ctx_cleanup
#define EVP_MD_CTX_create FIPS_md_ctx_create
#define EVP_MD_CTX_destroy FIPS_md_ctx_destroy
#define EVP_DigestInit_ex(ctx, type, impl) FIPS_digestinit(ctx, type)
#define EVP_DigestInit FIPS_digestinit
#define EVP_DigestUpdate FIPS_digestupdate
#define EVP_Digest(data, count, md, size, type, impl) \
			FIPS_digest(data, count, md, size, type)
#define EVP_DigestFinal_ex FIPS_digestfinal
#define EVP_MD_CTX_copy_ex FIPS_md_ctx_copy

#define EVP_CipherInit_ex(ctx, cipher, impl, key, iv, enc) \
				FIPS_cipherinit(ctx, cipher, key, iv, enc)

#define EVP_CipherInit FIPS_cipherinit

#define EVP_CIPHER_CTX_init FIPS_cipher_ctx_init
#define EVP_CIPHER_CTX_cleanup FIPS_cipher_ctx_cleanup
#define EVP_Cipher FIPS_cipher
#define EVP_CIPHER_CTX_ctrl FIPS_cipher_ctx_ctrl
#define EVP_CIPHER_CTX_new FIPS_cipher_ctx_new
#define EVP_CIPHER_CTX_free FIPS_cipher_ctx_free
#define EVP_CIPHER_CTX_copy FIPS_cipher_ctx_copy
#define EVP_CIPHER_CTX_set_key_length FIPS_cipher_ctx_set_key_length

#define DSA_SIG_new FIPS_dsa_sig_new
#define DSA_SIG_free FIPS_dsa_sig_free

#define ECDSA_SIG_new FIPS_ecdsa_sig_new
#define ECDSA_SIG_free FIPS_ecdsa_sig_free

#define ecdsa_check fips_ecdsa_check
#define ecdh_check fips_ecdh_check

#define RAND_bytes FIPS_rand_bytes
#define RAND_pseudo_bytes FIPS_rand_pseudo_bytes
#define RAND_add FIPS_rand_add
#define RAND_seed FIPS_rand_seed
#define RAND_status FIPS_rand_status

/* Rename symbols so they don't clash with standard OpenSSL */

#define AES_cfb128_encrypt fips_aes_cfb128_encrypt
#define AES_cfb1_encrypt fips_aes_cfb1_encrypt
#define AES_cfb8_encrypt fips_aes_cfb8_encrypt
#define AES_ecb_encrypt fips_aes_ecb_encrypt
#define AES_ofb128_encrypt fips_aes_ofb128_encrypt
#define BN_BLINDING_convert fips_bn_blinding_convert
#define BN_BLINDING_convert_ex fips_bn_blinding_convert_ex
#define BN_BLINDING_create_param fips_bn_blinding_create_param
#define BN_BLINDING_free fips_bn_blinding_free
#define BN_BLINDING_get_flags fips_bn_blinding_get_flags
#define BN_BLINDING_invert fips_bn_blinding_invert
#define BN_BLINDING_invert_ex fips_bn_blinding_invert_ex
#define BN_BLINDING_new fips_bn_blinding_new
#define BN_BLINDING_set_flags fips_bn_blinding_set_flags
#define BN_BLINDING_thread_id fips_bn_blinding_thread_id
#define BN_BLINDING_update fips_bn_blinding_update
#define BN_BLINDING_get_thread_id fips_bn_blinding_get_thread_id
#define BN_BLINDING_set_thread_id fips_bn_blinding_set_thread_id
#define BN_CTX_end fips_bn_ctx_end
#define BN_CTX_init fips_bn_ctx_init
#define BN_CTX_free fips_bn_ctx_free
#define BN_CTX_get fips_bn_ctx_get
#define BN_CTX_new fips_bn_ctx_new
#define BN_CTX_start fips_bn_ctx_start
#define BN_GENCB_call fips_bn_gencb_call
#define BN_GF2m_add fips_bn_gf2m_add
#define BN_GF2m_arr2poly fips_bn_gf2m_arr2poly
#define BN_GF2m_mod fips_bn_gf2m_mod
#define BN_GF2m_mod_arr fips_bn_gf2m_mod_arr
#define BN_GF2m_mod_div fips_bn_gf2m_mod_div
#define BN_GF2m_mod_div_arr fips_bn_gf2m_mod_div_arr
#define BN_GF2m_mod_exp fips_bn_gf2m_mod_exp
#define BN_GF2m_mod_exp_arr fips_bn_gf2m_mod_exp_arr
#define BN_GF2m_mod_inv fips_bn_gf2m_mod_inv
#define BN_GF2m_mod_inv_arr fips_bn_gf2m_mod_inv_arr
#define BN_GF2m_mod_mul fips_bn_gf2m_mod_mul
#define BN_GF2m_mod_mul_arr fips_bn_gf2m_mod_mul_arr
#define BN_GF2m_mod_solve_quad fips_bn_gf2m_mod_solve_quad
#define BN_GF2m_mod_solve_quad_arr fips_bn_gf2m_mod_solve_quad_arr
#define BN_GF2m_mod_sqr fips_bn_gf2m_mod_sqr
#define BN_GF2m_mod_sqr_arr fips_bn_gf2m_mod_sqr_arr
#define BN_GF2m_mod_sqrt fips_bn_gf2m_mod_sqrt
#define BN_GF2m_mod_sqrt_arr fips_bn_gf2m_mod_sqrt_arr
#define BN_GF2m_poly2arr fips_bn_gf2m_poly2arr
#define BN_MONT_CTX_copy fips_bn_mont_ctx_copy
#define BN_MONT_CTX_free fips_bn_mont_ctx_free
#define BN_MONT_CTX_init fips_bn_mont_ctx_init
#define BN_MONT_CTX_new fips_bn_mont_ctx_new
#define BN_MONT_CTX_set fips_bn_mont_ctx_set
#define BN_MONT_CTX_set_locked fips_bn_mont_ctx_set_locked
#define BN_RECP_CTX_free fips_bn_recp_ctx_free
#define BN_RECP_CTX_init fips_bn_recp_ctx_init
#define BN_RECP_CTX_new fips_bn_recp_ctx_new
#define BN_RECP_CTX_set fips_bn_recp_ctx_set
#define BN_X931_derive_prime_ex FIPS_bn_x931_derive_prime_ex
#define BN_X931_generate_Xpq FIPS_bn_x931_generate_xpq
#define BN_X931_generate_prime_ex FIPS_bn_x931_generate_prime_ex
#define BN_add fips_bn_add
#define BN_add_word fips_bn_add_word
#define BN_bin2bn FIPS_bn_bin2bn
#define BN_bn2bin FIPS_bn_bn2bin
#define BN_bntest_rand fips_bn_bntest_rand
#define BN_clear FIPS_bn_clear
#define BN_clear_bit fips_bn_clear_bit
#define BN_clear_free FIPS_bn_clear_free
#define BN_cmp fips_bn_cmp
#define BN_copy fips_bn_copy
#define BN_div fips_bn_div
#define BN_div_recp fips_bn_div_recp
#define BN_div_word fips_bn_div_word
#define BN_dup fips_bn_dup
#define BN_exp fips_bn_exp
#define BN_free FIPS_bn_free
#define BN_gcd fips_bn_gcd
#define BN_generate_prime_ex FIPS_bn_generate_prime_ex
#define BN_get0_nist_prime_192 fips_bn_get0_nist_prime_192
#define BN_get0_nist_prime_224 fips_bn_get0_nist_prime_224
#define BN_get0_nist_prime_256 fips_bn_get0_nist_prime_256
#define BN_get0_nist_prime_384 fips_bn_get0_nist_prime_384
#define BN_get0_nist_prime_521 fips_bn_get0_nist_prime_521
#define BN_get_word FIPS_bn_get_word
#define BN_init fips_bn_init
#define BN_is_bit_set FIPS_bn_is_bit_set
#define BN_is_prime_ex FIPS_bn_is_prime_ex
#define BN_is_prime_fasttest_ex FIPS_bn_is_prime_fasttest_ex
#define BN_lshift fips_bn_lshift
#define BN_lshift1 fips_bn_lshift1
#define BN_mask_bits fips_bn_mask_bits
#define BN_mod_add fips_bn_mod_add
#define BN_mod_add_quick fips_bn_mod_add_quick
#define BN_mod_exp fips_bn_mod_exp
#define BN_mod_exp2_mont fips_bn_mod_exp2_mont
#define BN_mod_exp_mont fips_bn_mod_exp_mont
#define BN_mod_exp_mont_consttime fips_bn_mod_exp_mont_consttime
#define BN_mod_exp_mont_word fips_bn_mod_exp_mont_word
#define BN_mod_exp_recp fips_bn_mod_exp_recp
#define BN_mod_exp_simple fips_bn_mod_exp_simple
#define BN_mod_inverse fips_bn_mod_inverse
#define BN_mod_lshift fips_bn_mod_lshift
#define BN_mod_lshift1 fips_bn_mod_lshift1
#define BN_mod_lshift1_quick fips_bn_mod_lshift1_quick
#define BN_mod_lshift_quick fips_bn_mod_lshift_quick
#define BN_mod_mul fips_bn_mod_mul
#define BN_mod_mul_montgomery fips_bn_mod_mul_montgomery
#define BN_mod_mul_reciprocal fips_bn_mod_mul_reciprocal
#define BN_mod_sqr fips_bn_mod_sqr
#define BN_mod_sub fips_bn_mod_sub
#define BN_mod_sub_quick fips_bn_mod_sub_quick
#define BN_mod_word fips_bn_mod_word
#define BN_mul fips_bn_mul
#define BN_mul_word fips_bn_mul_word
#define BN_new FIPS_bn_new
#define BN_nist_mod_192 fips_bn_nist_mod_192
#define BN_nist_mod_224 fips_bn_nist_mod_224
#define BN_nist_mod_256 fips_bn_nist_mod_256
#define BN_nist_mod_384 fips_bn_nist_mod_384
#define BN_nist_mod_521 fips_bn_nist_mod_521
#define BN_nist_mod_func fips_bn_nist_mod_func
#define BN_nnmod fips_bn_nnmod
#define BN_num_bits FIPS_bn_num_bits
#define BN_pseudo_rand FIPS_bn_pseudo_rand
#define BN_pseudo_rand_range FIPS_bn_pseudo_rand_range
#define BN_rand FIPS_bn_rand
#define BN_rand_range FIPS_bn_rand_range
#define BN_reciprocal fips_bn_reciprocal
#define BN_rshift fips_bn_rshift
#define BN_rshift1 fips_bn_rshift1
#define BN_set_bit FIPS_bn_set_bit
#define BN_set_negative fips_bn_set_negative
#define BN_set_word fips_bn_set_word
#define BN_sqr fips_bn_sqr
#define BN_sub fips_bn_sub
#define BN_sub_word fips_bn_sub_word
#define BN_swap fips_bn_swap
#define BN_uadd fips_bn_uadd
#define BN_ucmp fips_bn_ucmp
#define BN_usub fips_bn_usub
#define BN_value_one fips_bn_value_one
#define BN_set_params fips_bn_set_params
#define BN_get_params fips_bn_get_params
#define BN_version FIPS_bn_version
#define BUF_memdup fips_buf_memdup
#define BUF_strdup fips_buf_strdup
#define BUF_strlcat fips_buf_strlcat
#define BUF_strlcpy fips_buf_strlcpy
#define BUF_strndup fips_buf_strndup
#define DllMain	fips_dllmain
#define CRYPTO_THREADID_cmp fips_crypto_threadid_cmp
#define CRYPTO_THREADID_cpy fips_crypto_threadid_cpy
#define CRYPTO_THREADID_current fips_crypto_threadid_current
#define CRYPTO_THREADID_get_callback FIPS_crypto_threadid_get_callback
#define CRYPTO_THREADID_hash FIPS_crypto_threadid_hash
#define CRYPTO_THREADID_set_callback FIPS_crypto_threadid_set_callback
#define CRYPTO_THREADID_set_numeric FIPS_crypto_threadid_set_numeric
#define CRYPTO_THREADID_set_pointer FIPS_crypto_threadid_set_pointer
#define CRYPTO_get_id_callback FIPS_crypto_get_id_callback
#define CRYPTO_set_id_callback FIPS_crypto_set_id_callback
#define CRYPTO_thread_id FIPS_crypto_thread_id
#define CRYPTO_ccm128_aad fips_crypto_ccm128_aad
#define CRYPTO_ccm128_decrypt fips_crypto_ccm128_decrypt
#define CRYPTO_ccm128_decrypt_ccm64 fips_crypto_ccm128_decrypt_ccm64
#define CRYPTO_ccm128_encrypt fips_crypto_ccm128_encrypt
#define CRYPTO_ccm128_encrypt_ccm64 fips_crypto_ccm128_encrypt_ccm64
#define CRYPTO_ccm128_init fips_crypto_ccm128_init
#define CRYPTO_ccm128_setiv fips_crypto_ccm128_setiv
#define CRYPTO_ccm128_tag fips_crypto_ccm128_tag
#define CRYPTO_cbc128_decrypt fips_crypto_cbc128_decrypt
#define CRYPTO_cbc128_encrypt fips_crypto_cbc128_encrypt
#define CRYPTO_cfb128_1_encrypt fips_crypto_cfb128_1_encrypt
#define CRYPTO_cfb128_8_encrypt fips_crypto_cfb128_8_encrypt
#define CRYPTO_cfb128_encrypt fips_crypto_cfb128_encrypt
#define CRYPTO_ctr128_encrypt fips_crypto_ctr128_encrypt
#define CRYPTO_ctr128_encrypt_ctr32 fips_crypto_ctr128_encrypt_ctr32
#define CRYPTO_gcm128_aad fips_crypto_gcm128_aad
#define CRYPTO_gcm128_decrypt fips_crypto_gcm128_decrypt
#define CRYPTO_gcm128_decrypt_ctr32 fips_crypto_gcm128_decrypt_ctr32
#define CRYPTO_gcm128_encrypt fips_crypto_gcm128_encrypt
#define CRYPTO_gcm128_encrypt_ctr32 fips_crypto_gcm128_encrypt_ctr32
#define CRYPTO_gcm128_finish fips_crypto_gcm128_finish
#define CRYPTO_gcm128_init fips_crypto_gcm128_init
#define CRYPTO_gcm128_new fips_crypto_gcm128_new
#define CRYPTO_gcm128_release fips_crypto_gcm128_release
#define CRYPTO_gcm128_setiv fips_crypto_gcm128_setiv
#define CRYPTO_gcm128_tag fips_crypto_gcm128_tag
#define CRYPTO_ofb128_encrypt fips_crypto_ofb128_encrypt
#define CRYPTO_xts128_encrypt fips_crypto_xts128_encrypt
#define DES_cfb64_encrypt fips_des_cfb64_encrypt
#define DES_cfb_encrypt fips_des_cfb_encrypt
#define DES_check_key_parity FIPS_des_check_key_parity
#define DES_crypt fips_des_crypt
#define DES_ecb3_encrypt fips_des_ecb3_encrypt
#define DES_ede3_cfb64_encrypt fips_des_ede3_cfb64_encrypt
#define DES_ede3_cfb_encrypt fips_des_ede3_cfb_encrypt
#define DES_ede3_ofb64_encrypt fips_des_ede3_ofb64_encrypt
#define DES_fcrypt fips_des_fcrypt
#define DES_is_weak_key fips_des_is_weak_key
#define DES_key_sched fips_des_key_sched
#define DES_set_key fips_des_set_key
#define DES_set_key_checked fips_des_set_key_checked
#define DES_set_key_unchecked fips_des_set_key_unchecked
#define DES_set_odd_parity fips_des_set_odd_parity
#define DH_OpenSSL FIPS_dh_openssl
#define DH_check FIPS_dh_check
#define DH_check_pub_key FIPS_dh_check_pub_key
#define DH_compute_key FIPS_dh_compute_key
#define DH_generate_key FIPS_dh_generate_key
#define DH_generate_parameters_ex FIPS_dh_generate_parameters_ex
#define DSA_OpenSSL FIPS_dsa_openssl
#define DSA_generate_key FIPS_dsa_generate_key
#define DSA_generate_parameters_ex FIPS_dsa_generate_parameters_ex
#define ECDSA_OpenSSL FIPS_ecdsa_openssl
#define EC_EX_DATA_clear_free_all_data fips_ec_ex_data_clear_free_all_data
#define EC_EX_DATA_clear_free_data fips_ec_ex_data_clear_free_data
#define EC_EX_DATA_free_all_data fips_ec_ex_data_free_all_data
#define EC_EX_DATA_free_data fips_ec_ex_data_free_data
#define EC_EX_DATA_get_data fips_ec_ex_data_get_data
#define EC_EX_DATA_set_data fips_ec_ex_data_set_data
#define EC_GF2m_simple_method fips_ec_gf2m_simple_method
#define EC_GFp_mont_method fips_ec_gfp_mont_method
#define EC_GFp_nist_method fips_ec_gfp_nist_method
#define EC_GFp_simple_method fips_ec_gfp_simple_method
#define EC_GROUP_check_discriminant fips_ec_group_check_discriminant
#define EC_GROUP_clear_free FIPS_ec_group_clear_free
#define EC_GROUP_cmp fips_ec_group_cmp
#define EC_GROUP_copy fips_ec_group_copy
#define EC_GROUP_dup fips_ec_group_dup
#define EC_GROUP_free fips_ec_group_free
#define EC_GROUP_get0_generator FIPS_ec_group_get0_generator
#define EC_GROUP_get0_seed FIPS_ec_group_get0_seed
#define EC_GROUP_get_asn1_flag FIPS_ec_group_get_asn1_flag
#define EC_GROUP_get_cofactor FIPS_ec_group_get_cofactor
#define EC_GROUP_get_curve_GF2m FIPS_ec_group_get_curve_gf2m
#define EC_GROUP_get_curve_GFp FIPS_ec_group_get_curve_gfp
#define EC_GROUP_get_curve_name FIPS_ec_group_get_curve_name
#define EC_GROUP_get_degree FIPS_ec_group_get_degree
#define EC_GROUP_get_order FIPS_ec_group_get_order
#define EC_GROUP_get_point_conversion_form fips_ec_group_get_point_conversion_form
#define EC_GROUP_get_seed_len fips_ec_group_get_seed_len
#define EC_GROUP_have_precompute_mult fips_ec_group_have_precompute_mult
#define EC_GROUP_method_of FIPS_ec_group_method_of
#define EC_GROUP_new FIPS_ec_group_new
#define EC_GROUP_new_by_curve_name FIPS_ec_group_new_by_curve_name
#define EC_GROUP_new_curve_GF2m FIPS_ec_group_new_curve_gf2m
#define EC_GROUP_new_curve_GFp FIPS_ec_group_new_curve_gfp
#define EC_GROUP_precompute_mult FIPS_ec_group_precompute_mult
#define EC_GROUP_set_asn1_flag FIPS_ec_group_set_asn1_flag
#define EC_GROUP_set_curve_GF2m FIPS_ec_group_set_curve_gf2m
#define EC_GROUP_set_curve_GFp FIPS_ec_group_set_curve_gfp
#define EC_GROUP_set_curve_name FIPS_ec_group_set_curve_name
#define EC_GROUP_set_generator FIPS_ec_group_set_generator
#define EC_GROUP_set_point_conversion_form FIPS_ec_group_set_point_conversion_form
#define EC_GROUP_set_seed fips_ec_group_set_seed
#define EC_KEY_check_key FIPS_ec_key_check_key
#define EC_KEY_copy FIPS_ec_key_copy
#define EC_KEY_dup FIPS_ec_key_dup
#define EC_KEY_free FIPS_ec_key_free
#define EC_KEY_generate_key FIPS_ec_key_generate_key
#define EC_KEY_get0_group FIPS_ec_key_get0_group
#define EC_KEY_get0_private_key FIPS_ec_key_get0_private_key
#define EC_KEY_get0_public_key FIPS_ec_key_get0_public_key
#define EC_KEY_get_conv_form FIPS_ec_key_get_conv_form
#define EC_KEY_get_enc_flags FIPS_ec_key_get_enc_flags
#define EC_KEY_get_key_method_data FIPS_ec_key_get_key_method_data
#define EC_KEY_insert_key_method_data FIPS_ec_key_insert_key_method_data
#define EC_KEY_new FIPS_ec_key_new
#define EC_KEY_new_by_curve_name FIPS_ec_key_new_by_curve_name
#define EC_KEY_precompute_mult FIPS_ec_key_precompute_mult
#define EC_KEY_set_asn1_flag FIPS_ec_key_set_asn1_flag
#define EC_KEY_set_conv_form FIPS_ec_key_set_conv_form
#define EC_KEY_set_enc_flags FIPS_ec_key_set_enc_flags
#define EC_KEY_set_flags FIPS_ec_key_set_flags
#define EC_KEY_clear_flags FIPS_ec_key_clear_flags
#define EC_KEY_get_flags FIPS_ec_key_get_flags
#define EC_KEY_set_group FIPS_ec_key_set_group
#define EC_KEY_set_private_key FIPS_ec_key_set_private_key
#define EC_KEY_set_public_key FIPS_ec_key_set_public_key
#define EC_KEY_set_public_key_affine_coordinates FIPS_ec_key_set_public_key_affine_coordinates
#define EC_KEY_up_ref FIPS_ec_key_up_ref
#define EC_METHOD_get_field_type FIPS_ec_method_get_field_type
#define EC_POINT_add fips_ec_point_add
#define EC_POINT_clear_free FIPS_ec_point_clear_free
#define EC_POINT_cmp fips_ec_point_cmp
#define EC_POINT_copy fips_ec_point_copy
#define EC_POINT_dbl fips_ec_point_dbl
#define EC_POINT_dup fips_ec_point_dup
#define EC_POINT_free FIPS_ec_point_free
#define EC_POINT_get_Jprojective_coordinates_GFp FIPS_ec_point_get_jprojective_coordinates_gfp
#define EC_POINT_get_affine_coordinates_GF2m FIPS_ec_point_get_affine_coordinates_gf2m
#define EC_POINT_get_affine_coordinates_GFp FIPS_ec_point_get_affine_coordinates_gfp
#define EC_POINT_invert fips_ec_point_invert
#define EC_POINT_is_at_infinity FIPS_ec_point_is_at_infinity
#define EC_POINT_is_on_curve FIPS_ec_point_is_on_curve
#define EC_POINT_make_affine FIPS_ec_point_make_affine
#define EC_POINT_method_of FIPS_ec_point_method_of
#define EC_POINT_mul FIPS_ec_point_mul
#define EC_POINT_new FIPS_ec_point_new
#define EC_POINT_set_Jprojective_coordinates_GFp fips_ec_point_set_jprojective_coordinates_gfp
#define EC_POINT_set_affine_coordinates_GF2m fips_ec_point_set_affine_coordinates_gf2m
#define EC_POINT_set_affine_coordinates_GFp fips_ec_point_set_affine_coordinates_gfp
#define EC_POINT_set_to_infinity FIPS_ec_point_set_to_infinity
#define EC_POINTs_make_affine FIPS_ec_points_make_affine
#define EC_POINTs_mul fips_ec_points_mul
#define EC_get_builtin_curves FIPS_ec_get_builtin_curves
#define EVP_aes_128_cbc FIPS_evp_aes_128_cbc
#define EVP_aes_128_ccm FIPS_evp_aes_128_ccm
#define EVP_aes_128_cfb1 FIPS_evp_aes_128_cfb1
#define EVP_aes_128_cfb128 FIPS_evp_aes_128_cfb128
#define EVP_aes_128_cfb8 FIPS_evp_aes_128_cfb8
#define EVP_aes_128_ctr FIPS_evp_aes_128_ctr
#define EVP_aes_128_ecb FIPS_evp_aes_128_ecb
#define EVP_aes_128_gcm FIPS_evp_aes_128_gcm
#define EVP_aes_128_ofb FIPS_evp_aes_128_ofb
#define EVP_aes_128_xts FIPS_evp_aes_128_xts
#define EVP_aes_192_cbc FIPS_evp_aes_192_cbc
#define EVP_aes_192_ccm FIPS_evp_aes_192_ccm
#define EVP_aes_192_cfb1 FIPS_evp_aes_192_cfb1
#define EVP_aes_192_cfb128 FIPS_evp_aes_192_cfb128
#define EVP_aes_192_cfb8 FIPS_evp_aes_192_cfb8
#define EVP_aes_192_ctr FIPS_evp_aes_192_ctr
#define EVP_aes_192_ecb FIPS_evp_aes_192_ecb
#define EVP_aes_192_gcm FIPS_evp_aes_192_gcm
#define EVP_aes_192_ofb FIPS_evp_aes_192_ofb
#define EVP_aes_256_cbc FIPS_evp_aes_256_cbc
#define EVP_aes_256_ccm FIPS_evp_aes_256_ccm
#define EVP_aes_256_cfb1 FIPS_evp_aes_256_cfb1
#define EVP_aes_256_cfb128 FIPS_evp_aes_256_cfb128
#define EVP_aes_256_cfb8 FIPS_evp_aes_256_cfb8
#define EVP_aes_256_ctr FIPS_evp_aes_256_ctr
#define EVP_aes_256_ecb FIPS_evp_aes_256_ecb
#define EVP_aes_256_gcm FIPS_evp_aes_256_gcm
#define EVP_aes_256_ofb FIPS_evp_aes_256_ofb
#define EVP_aes_256_xts FIPS_evp_aes_256_xts
#define EVP_des_ede FIPS_evp_des_ede
#define EVP_des_ede3 FIPS_evp_des_ede3
#define EVP_des_ede3_cbc FIPS_evp_des_ede3_cbc
#define EVP_des_ede3_cfb1 FIPS_evp_des_ede3_cfb1
#define EVP_des_ede3_cfb64 FIPS_evp_des_ede3_cfb64
#define EVP_des_ede3_cfb8 FIPS_evp_des_ede3_cfb8
#define EVP_des_ede3_ecb FIPS_evp_des_ede3_ecb
#define EVP_des_ede3_ofb FIPS_evp_des_ede3_ofb
#define EVP_des_ede_cbc FIPS_evp_des_ede_cbc
#define EVP_des_ede_cfb64 FIPS_evp_des_ede_cfb64
#define EVP_des_ede_ecb FIPS_evp_des_ede_ecb
#define EVP_des_ede_ofb FIPS_evp_des_ede_ofb
#define EVP_enc_null FIPS_evp_enc_null
#define EVP_sha1 FIPS_evp_sha1
#define EVP_dss FIPS_evp_dss
#define EVP_dss1 FIPS_evp_dss1
#define EVP_ecdsa FIPS_evp_ecdsa
#define EVP_sha224 FIPS_evp_sha224
#define EVP_sha256 FIPS_evp_sha256
#define EVP_sha384 FIPS_evp_sha384
#define EVP_sha512 FIPS_evp_sha512
#define HMAC FIPS_hmac
#define HMAC_CTX_cleanup FIPS_hmac_ctx_cleanup
#define HMAC_CTX_copy FIPS_hmac_ctx_copy
#define HMAC_CTX_init FIPS_hmac_ctx_init
#define HMAC_CTX_set_flags FIPS_hmac_ctx_set_flags
#define HMAC_Final FIPS_hmac_final
#define HMAC_Init FIPS_hmac_init
#define HMAC_Init_ex FIPS_hmac_init_ex
#define HMAC_Update FIPS_hmac_update
#define OPENSSL_NONPIC_relocated fips_openssl_nonpic_relocated
#define OPENSSL_ia32cap_loc fips_openssl_ia32cap_loc
#define OPENSSL_isservice fips_openssl_isservice
#define OPENSSL_issetugid fips_openssl_issetugid
#define OPENSSL_showfatal FIPS_openssl_showfatal
#define OPENSSL_stderr FIPS_openssl_stderr
#define OpenSSLDie FIPS_openssldie
#define PKCS1_MGF1 fips_pkcs1_mgf1
#define RSA_PKCS1_SSLeay FIPS_rsa_pkcs1_ssleay
#define RSA_X931_derive_ex FIPS_rsa_x931_derive_ex
#define RSA_X931_generate_key_ex FIPS_rsa_x931_generate_key_ex
#define RSA_X931_hash_id fips_rsa_x931_hash_id
#define RSA_blinding_off FIPS_rsa_blinding_off
#define RSA_blinding_on FIPS_rsa_blinding_on
#define RSA_flags FIPS_rsa_flags
#define RSA_generate_key_ex FIPS_rsa_generate_key_ex
#define RSA_padding_add_PKCS1_OAEP fips_rsa_padding_add_pkcs1_oaep
#define RSA_padding_add_PKCS1_PSS fips_rsa_padding_add_pkcs1_pss
#define RSA_padding_add_PKCS1_PSS_mgf1 fips_rsa_padding_add_pkcs1_pss_mgf1
#define RSA_padding_add_PKCS1_type_1 fips_rsa_padding_add_pkcs1_type_1
#define RSA_padding_add_PKCS1_type_2 fips_rsa_padding_add_pkcs1_type_2
#define RSA_padding_add_SSLv23 fips_rsa_padding_add_sslv23
#define RSA_padding_add_X931 fips_rsa_padding_add_x931
#define RSA_padding_add_none fips_rsa_padding_add_none
#define RSA_padding_check_PKCS1_OAEP fips_rsa_padding_check_pkcs1_oaep
#define RSA_padding_check_PKCS1_type_1 fips_rsa_padding_check_pkcs1_type_1
#define RSA_padding_check_PKCS1_type_2 fips_rsa_padding_check_pkcs1_type_2
#define RSA_padding_check_SSLv23 fips_rsa_padding_check_sslv23
#define RSA_padding_check_X931 fips_rsa_padding_check_x931
#define RSA_padding_check_none fips_rsa_padding_check_none
#define RSA_private_decrypt FIPS_rsa_private_decrypt
#define RSA_private_encrypt FIPS_rsa_private_encrypt
#define RSA_public_decrypt FIPS_rsa_public_decrypt
#define RSA_public_encrypt FIPS_rsa_public_encrypt
#define RSA_setup_blinding fips_rsa_setup_blinding
#define RSA_size FIPS_rsa_size
#define RSA_verify_PKCS1_PSS fips_rsa_verify_pkcs1_pss
#define RSA_verify_PKCS1_PSS_mgf1 fips_rsa_verify_pkcs1_pss_mgf1
#define SHA1_Final fips_sha1_final
#define SHA1_Init fips_sha1_init
#define SHA1_Transform fips_sha1_transform
#define SHA1_Update fips_sha1_update
#define SHA1_version fips_sha1_version
#define SHA224 fips_sha224
#define SHA224_Final fips_sha224_final
#define SHA224_Init fips_sha224_init
#define SHA224_Update fips_sha224_update
#define SHA256_Final fips_sha256_final
#define SHA256_Init fips_sha256_init
#define SHA256_Transform fips_sha256_transform
#define SHA256_Update fips_sha256_update
#define SHA256_version fips_sha256_version
#define SHA384 fips_sha384
#define SHA384_Final fips_sha384_final
#define SHA384_Init fips_sha384_init
#define SHA384_Update fips_sha384_update
#define SHA512_Final fips_sha512_final
#define SHA512_Init fips_sha512_init
#define SHA512_Transform fips_sha512_transform
#define SHA512_Update fips_sha512_update
#define SHA512_version fips_sha512_version
#define _shadow_DES_check_key fips__shadow_des_check_key
#define aes_t4_decrypt fips_aes_t4_decrypt
#define aes_t4_encrypt fips_aes_t4_encrypt
#define aes_t4_set_decrypt_key fips_aes_t4_set_decrypt_key
#define aes_t4_set_encrypt_key fips_aes_t4_set_encrypt_key
#define aes128_t4_cbc_decrypt fips_aes128_t4_cbc_decrypt
#define aes128_t4_cbc_encrypt fips_aes128_t4_cbc_encrypt
#define aes128_t4_ctr32_encrypt fips_aes128_t4_ctr32_encrypt
#define aes128_t4_xts_decrypt fips_aes128_t4_xts_decrypt
#define aes128_t4_xts_encrypt fips_aes128_t4_xts_encrypt
#define aes192_t4_cbc_decrypt fips_aes192_t4_cbc_decrypt
#define aes192_t4_cbc_encrypt fips_aes192_t4_cbc_encrypt
#define aes192_t4_ctr32_encrypt fips_aes192_t4_ctr32_encrypt
#define aes256_t4_cbc_decrypt fips_aes256_t4_cbc_decrypt
#define aes256_t4_cbc_encrypt fips_aes256_t4_cbc_encrypt
#define aes256_t4_ctr32_encrypt fips_aes256_t4_ctr32_encrypt
#define aes256_t4_xts_decrypt fips_aes256_t4_xts_decrypt
#define aes256_t4_xts_encrypt fips_aes256_t4_xts_encrypt
#define bn_GF2m_mul_2x2 fips_bn_GF2m_mul_2x2
#define bn_add_part_words fips_bn_add_part_words
#define bn_cmp_part_words fips_bn_cmp_part_words
#define bn_cmp_words fips_bn_cmp_words
#define bn_dup_expand fips_bn_dup_expand
#define bn_expand2 fips_bn_expand2
#define bn_flip_n_scatter5_t4 fips_bn_flip_n_scatter5_t4
#define bn_flip_t4 fips_bn_flip_t4
#define bn_gather5_t4 fips_bn_gather5_t4
#define bn_mul_high fips_bn_mul_high
#define bn_mul_low_normal fips_bn_mul_low_normal
#define bn_mul_low_recursive fips_bn_mul_low_recursive
#define bn_mul_mont_gather5_t4 fips_bn_mul_mont_gather5_t4
#define bn_mul_mont_t4 fips_bn_mul_mont_t4
#define bn_mul_mont_t4_8 fips_bn_mul_mont_t4_8
#define bn_mul_mont_t4_16 fips_bn_mul_mont_t4_16
#define bn_mul_mont_t4_24 fips_bn_mul_mont_t4_24
#define bn_mul_mont_t4_32 fips_bn_mul_mont_t4_32
#define bn_mul_mont_vis3 fips_bn_mul_mont_vis3
#define bn_mul_normal fips_bn_mul_normal
#define bn_mul_part_recursive fips_bn_mul_part_recursive
#define bn_mul_recursive fips_bn_mul_recursive
#define bn_pwr5_mont_t4_8 fips_bn_pwr5_mont_t4_8
#define bn_pwr5_mont_t4_16 fips_bn_pwr5_mont_t4_16
#define bn_pwr5_mont_t4_24 fips_bn_pwr5_mont_t4_24
#define bn_pwr5_mont_t4_32 fips_bn_pwr5_mont_t4_32
#define bn_sqr_normal fips_bn_sqr_normal
#define bn_sqr_recursive fips_bn_sqr_recursive
#define des_t4_cbc_decrypt fips_des_t4_cbc_decrypt
#define des_t4_cbc_encrypt fips_des_t4_cbc_encrypt
#define des_t4_ede3_cbc_decrypt fips_des_t4_ede3_cbc_decrypt
#define des_t4_ede3_cbc_encrypt fips_des_t4_ede3_cbc_encrypt
#define des_t4_key_expand fips_des_t4_key_expand
#define dsa_builtin_paramgen fips_dsa_builtin_paramgen
#define dsa_builtin_paramgen2 fips_dsa_builtin_paramgen2
#define dsa_paramgen_check_g fips_dsa_paramgen_check_g
#define ec_GF2m_have_precompute_mult fips_ec_gf2m_have_precompute_mult
#define ec_GF2m_precompute_mult fips_ec_gf2m_precompute_mult
#define ec_GF2m_simple_add fips_ec_gf2m_simple_add
#define ec_GF2m_simple_cmp fips_ec_gf2m_simple_cmp
#define ec_GF2m_simple_dbl fips_ec_gf2m_simple_dbl
#define ec_GF2m_simple_field_div fips_ec_gf2m_simple_field_div
#define ec_GF2m_simple_field_mul fips_ec_gf2m_simple_field_mul
#define ec_GF2m_simple_field_sqr fips_ec_gf2m_simple_field_sqr
#define ec_GF2m_simple_group_check_discriminant fips_ec_gf2m_simple_group_check_discriminant
#define ec_GF2m_simple_group_clear_finish fips_ec_gf2m_simple_group_clear_finish
#define ec_GF2m_simple_group_copy fips_ec_gf2m_simple_group_copy
#define ec_GF2m_simple_group_finish fips_ec_gf2m_simple_group_finish
#define ec_GF2m_simple_group_get_curve fips_ec_gf2m_simple_group_get_curve
#define ec_GF2m_simple_group_get_degree fips_ec_gf2m_simple_group_get_degree
#define ec_GF2m_simple_group_init fips_ec_gf2m_simple_group_init
#define ec_GF2m_simple_group_set_curve fips_ec_gf2m_simple_group_set_curve
#define ec_GF2m_simple_invert fips_ec_gf2m_simple_invert
#define ec_GF2m_simple_is_at_infinity fips_ec_gf2m_simple_is_at_infinity
#define ec_GF2m_simple_is_on_curve fips_ec_gf2m_simple_is_on_curve
#define ec_GF2m_simple_make_affine fips_ec_gf2m_simple_make_affine
#define ec_GF2m_simple_mul fips_ec_gf2m_simple_mul
#define ec_GF2m_simple_point_clear_finish fips_ec_gf2m_simple_point_clear_finish
#define ec_GF2m_simple_point_copy fips_ec_gf2m_simple_point_copy
#define ec_GF2m_simple_point_finish fips_ec_gf2m_simple_point_finish
#define ec_GF2m_simple_point_get_affine_coordinates fips_ec_gf2m_simple_point_get_affine_coordinates
#define ec_GF2m_simple_point_init fips_ec_gf2m_simple_point_init
#define ec_GF2m_simple_point_set_affine_coordinates fips_ec_gf2m_simple_point_set_affine_coordinates
#define ec_GF2m_simple_point_set_to_infinity fips_ec_gf2m_simple_point_set_to_infinity
#define ec_GF2m_simple_points_make_affine fips_ec_gf2m_simple_points_make_affine
#define ec_GFp_mont_field_decode fips_ec_gfp_mont_field_decode
#define ec_GFp_mont_field_encode fips_ec_gfp_mont_field_encode
#define ec_GFp_mont_field_mul fips_ec_gfp_mont_field_mul
#define ec_GFp_mont_field_set_to_one fips_ec_gfp_mont_field_set_to_one
#define ec_GFp_mont_field_sqr fips_ec_gfp_mont_field_sqr
#define ec_GFp_mont_group_clear_finish fips_ec_gfp_mont_group_clear_finish
#define ec_GFp_mont_group_copy fips_ec_gfp_mont_group_copy
#define ec_GFp_mont_group_finish fips_ec_gfp_mont_group_finish
#define ec_GFp_mont_group_init fips_ec_gfp_mont_group_init
#define ec_GFp_mont_group_set_curve fips_ec_gfp_mont_group_set_curve
#define ec_GFp_nist_field_mul fips_ec_gfp_nist_field_mul
#define ec_GFp_nist_field_sqr fips_ec_gfp_nist_field_sqr
#define ec_GFp_nist_group_copy fips_ec_gfp_nist_group_copy
#define ec_GFp_nist_group_set_curve fips_ec_gfp_nist_group_set_curve
#define ec_GFp_simple_add fips_ec_gfp_simple_add
#define ec_GFp_simple_cmp fips_ec_gfp_simple_cmp
#define ec_GFp_simple_dbl fips_ec_gfp_simple_dbl
#define ec_GFp_simple_field_mul fips_ec_gfp_simple_field_mul
#define ec_GFp_simple_field_sqr fips_ec_gfp_simple_field_sqr
#define ec_GFp_simple_get_Jprojective_coordinates_GFp fips_ec_gfp_simple_get_jprojective_coordinates_gfp
#define ec_GFp_simple_group_check_discriminant fips_ec_gfp_simple_group_check_discriminant
#define ec_GFp_simple_group_clear_finish fips_ec_gfp_simple_group_clear_finish
#define ec_GFp_simple_group_copy fips_ec_gfp_simple_group_copy
#define ec_GFp_simple_group_finish fips_ec_gfp_simple_group_finish
#define ec_GFp_simple_group_get_curve fips_ec_gfp_simple_group_get_curve
#define ec_GFp_simple_group_get_degree fips_ec_gfp_simple_group_get_degree
#define ec_GFp_simple_group_init fips_ec_gfp_simple_group_init
#define ec_GFp_simple_group_set_curve fips_ec_gfp_simple_group_set_curve
#define ec_GFp_simple_invert fips_ec_gfp_simple_invert
#define ec_GFp_simple_is_at_infinity fips_ec_gfp_simple_is_at_infinity
#define ec_GFp_simple_is_on_curve fips_ec_gfp_simple_is_on_curve
#define ec_GFp_simple_make_affine fips_ec_gfp_simple_make_affine
#define ec_GFp_simple_point_clear_finish fips_ec_gfp_simple_point_clear_finish
#define ec_GFp_simple_point_copy fips_ec_gfp_simple_point_copy
#define ec_GFp_simple_point_finish fips_ec_gfp_simple_point_finish
#define ec_GFp_simple_point_get_affine_coordinates fips_ec_gfp_simple_point_get_affine_coordinates
#define ec_GFp_simple_point_init fips_ec_gfp_simple_point_init
#define ec_GFp_simple_point_set_affine_coordinates fips_ec_gfp_simple_point_set_affine_coordinates
#define ec_GFp_simple_point_set_to_infinity fips_ec_gfp_simple_point_set_to_infinity
#define ec_GFp_simple_points_make_affine fips_ec_gfp_simple_points_make_affine
#define ec_GFp_simple_set_Jprojective_coordinates_GFp fips_ec_gfp_simple_set_jprojective_coordinates_gfp
#define ec_wNAF_have_precompute_mult fips_ec_wnaf_have_precompute_mult
#define ec_wNAF_mul fips_ec_wnaf_mul
#define ec_wNAF_precompute_mult fips_ec_wnaf_precompute_mult
#define int_bn_mod_inverse fips_int_bn_mod_inverse
#define cleanse_ctr fips_cleanse_ctr
#define DH_compute_key_padded FIPS_dh_compute_key_padded
#define ECDH_OpenSSL FIPS_ecdh_openssl
#define ECDH_compute_key FIPS_ecdh_compute_key

#define CMAC_CTX_cleanup FIPS_cmac_ctx_cleanup
#define CMAC_CTX_copy FIPS_cmac_ctx_copy
#define CMAC_CTX_free FIPS_cmac_ctx_free
#define CMAC_CTX_get0_cipher_ctx FIPS_cmac_ctx_get0_cipher_ctx
#define CMAC_CTX_new FIPS_cmac_ctx_new
#define CMAC_Init FIPS_cmac_init
#define CMAC_Update FIPS_cmac_update
#define CMAC_Final FIPS_cmac_final
#define CMAC_resume FIPS_cmac_resume

/* assembler symbols */
#define gcm_gmult_4bit_x86 fips_gcm_gmult_4bit_x86
#define gcm_ghash_4bit_x86 fips_gcm_ghash_4bit_x86
#define gcm_init_avx fips_gcm_init_avx
#define gcm_gmult_avx fips_gcm_gmult_avx
#define gcm_ghash_avx fips_gcm_ghash_avx
#define AES_cbc_encrypt fips_aes_cbc_encrypt
#define AES_decrypt fips_aes_decrypt
#define AES_encrypt fips_aes_encrypt
#define AES_set_decrypt_key fips_aes_set_decrypt_key
#define AES_set_encrypt_key fips_aes_set_encrypt_key
#define AES_ctr32_encrypt fips_aes_ctr32_encrypt
#define BN_from_montgomery fips_bn_from_montgomery
#define BN_num_bits_word FIPS_bn_num_bits_word
#define DES_SPtrans fips_des_sptrans
#define DES_decrypt3 fips_des_decrypt3
#define DES_ede3_cbc_encrypt fips_des_ede3_cbc_encrypt
#define DES_encrypt1 fips_des_encrypt1
#define DES_encrypt2 fips_des_encrypt2
#define DES_encrypt3 fips_des_encrypt3
#define DES_ncbc_encrypt fips_des_ncbc_encrypt
#define OPENSSL_altivec_probe fips_openssl_altivec_probe
#define OPENSSL_atomic_add fips_openssl_atomic_add
#define OPENSSL_cleanse FIPS_openssl_cleanse
#define OPENSSL_cpuid_setup fips_openssl_cpuid_setup
#define OPENSSL_ia32_cpuid fips_openssl_ia32_cpuid
#define OPENSSL_ia32cap_P fips_openssl_ia32cap_p
#define OPENSSL_instrument_bus fips_openssl_instrument_bus
#define OPENSSL_instrument_bus2 fips_openssl_instrument_bus2
#define OPENSSL_ppc64_probe fips_openssl_ppc64_probe
#define OPENSSL_rdtsc fips_openssl_rdtsc
#define OPENSSL_wipe_cpu fips_openssl_wipe_cpu
#define SHA256 fips_sha256
#define SHA512 fips_sha512
#define aesni_ccm64_decrypt_blocks fips_aesni_ccm64_decrypt_blocks
#define aesni_ccm64_encrypt_blocks fips_aesni_ccm64_encrypt_blocks
#define aesni_ctr32_encrypt_blocks fips_aesni_ctr32_encrypt_blocks
#define aesni_ecb_encrypt fips_aesni_ecb_encrypt
#define aesni_encrypt fips_aesni_encrypt
#define bn_add_words fips_bn_add_words
#define bn_div_words fips_bn_div_words
#define bn_mul_add_words fips_bn_mul_add_words
#define bn_mul_comba4 fips_bn_mul_comba4
#define bn_mul_comba8 fips_bn_mul_comba8
#define bn_mul_mont fips_bn_mul_mont
#define bn_sqr_mont fips_bn_sqr_mont
#define bn_mul_mont_fpu64 fips_bn_mul_mont_fpu64
#define bn_mul_mont_int fips_bn_mul_mont_int
#define bn_mul_words fips_bn_mul_words
#define bn_sqr_comba4 fips_bn_sqr_comba4
#define bn_sqr_comba8 fips_bn_sqr_comba8
#define bn_sqr_words fips_bn_sqr_words
#define bn_sub_part_words fips_bn_sub_part_words
#define bn_sub_words fips_bn_sub_words
#define fcrypt_body fips_fcrypt_body
#define gcm_ghash_4bit fips_gcm_ghash_4bit
#define gcm_ghash_clmul fips_gcm_ghash_clmul
#define gcm_gmult_4bit fips_gcm_gmult_4bit
#define gcm_gmult_clmul fips_gcm_gmult_clmul
#define gcm_init_clmul fips_gcm_init_clmul
#define sha1_block_data_order fips_sha1_block_data_order
#define sha256_block_data_order fips_sha256_block_data_order
#define sha512_block_data_order fips_sha512_block_data_order
#define gcm_gmult_4bit_mmx fips_gcm_gmult_4bit_mmx
#define gcm_ghash_4bit_mmx fips_gcm_ghash_4bit_mmx
#define OPENSSL_far_spin fips_openssl_far_spin
#define OPENSSL_indirect_call fips_openssl_indirect_call
#define OPENSSL_instrument_halt fips_openssl_instrument_halt
#define OPENSSL_armcap fips_openssl_armcap
#define aesni_cbc_encrypt fips_aesni_cbc_encrypt
#define aesni_decrypt fips_aesni_decrypt
#define aesni_set_decrypt_key fips_aesni_set_decrypt_key
#define aesni_set_encrypt_key fips_aesni_set_encrypt_key
#define bn_GF2m_mul_2x2 fips_bn_GF2m_mul_2x2
#define gcm_ghash_neon fips_gcm_ghash_neon
#define gcm_gmult_neon fips_gcm_gmult_neon
#define aesni_xts_decrypt fips_aesni_xts_decrypt
#define aesni_xts_encrypt fips_aesni_xts_encrypt
#define OPENSSL_ia32_rdrand fips_openssl_ia32_rdrand
#define OPENSSL_armcap_P fips_openssl_armcap_P
#define _armv7_neon_probe _fips_armv7_neon_probe
#define _armv7_tick _fips_armv7_tick
#define _sparcv9_rdtick _fips_sparcv9_rdtick
#define _sparcv9_vis1_probe _fips_sparcv9_vis1_probe
#define _sparcv9_vis2_probe _fips_sparcv9_vis2_probe
#define _sparcv9_fmadd_probe _fips_sparcv9_fmadd_probe
#define _sparcv9_vis1_instrument _fips_sparcv9_vis1_instrument
#define bn_mul_mont_gather5 fips_bn_mul_mont_gather5
#define bn_scatter5 fips_bn_scatter5
#define bn_gather5 fips_bn_gather5
#define _armv8_aes_probe _fips_armv8_aes_probe
#define _armv8_pmull_probe _fips_armv8_pmull_probe
#define _armv8_sha1_probe _fips_armv8_sha1_probe
#define _armv8_sha256_probe _fips_armv8_sha256_probe
#define aes_v8_encrypt fips_aes_v8_encrypt
#define aes_v8_decrypt fips_aes_v8_decrypt
#define aes_v8_set_encrypt_key fips_aes_v8_set_encrypt_key
#define aes_v8_set_decrypt_key fips_aes_v8_set_decrypt_key
#define aes_v8_cbc_encrypt fips_aes_v8_cbc_encrypt
#define aes_v8_ctr32_encrypt_blocks fips_aes_v8_ctr32_encrypt_blocks
#define gcm_init_v8 fips_gcm_init_v8
#define gcm_gmult_v8 fips_gcm_gmult_v8
#define gcm_ghash_v8 fips_gcm_ghash_v8
#if defined(__APPLE__) && __ASSEMBLER__
#define _OPENSSL_armcap_P _fips_openssl_armcap_P
#define __armv7_neon_probe __fips_armv7_neon_probe
#define __armv7_tick __fips_armv7_tick
#define __armv8_aes_probe __fips_armv8_aes_probe
#define __armv8_pmull_probe __fips_armv8_pmull_probe
#define __armv8_sha1_probe __fips_armv8_sha1_probe
#define __armv8_sha256_probe __fips_armv8_sha256_probe
#define _aes_v8_encrypt _fips_aes_v8_encrypt
#define _aes_v8_decrypt _fips_aes_v8_decrypt
#define _aes_v8_set_encrypt_key _fips_aes_v8_set_encrypt_key
#define _aes_v8_set_decrypt_key _fips_aes_v8_set_decrypt_key
#define _aes_v8_cbc_encrypt _fips_aes_v8_cbc_encrypt
#define _aes_v8_ctr32_encrypt_blocks _fips_aes_v8_ctr32_encrypt_blocks
#define _gcm_init_v8 _fips_gcm_init_v8
#define _gcm_gmult_v8 _fips_gcm_gmult_v8
#define _gcm_ghash_v8 _fips_gcm_ghash_v8
#define _sha1_block_data_order _fips_sha1_block_data_order
#define _sha256_block_data_order _fips_sha256_block_data_order
#define _sha512_block_data_order _fips_sha512_block_data_order
#define _AES_decrypt _fips_aes_decrypt
#define _AES_encrypt _fips_aes_encrypt
#define _AES_set_decrypt_key _fips_aes_set_decrypt_key
#define _AES_set_encrypt_key _fips_aes_set_encrypt_key
#define _gcm_gmult_4bit _fips_gcm_gmult_4bit
#define _gcm_ghash_4bit _fips_gcm_ghash_4bit
#define _gcm_gmult_neon _fips_gcm_gmult_neon
#define _gcm_ghash_neon _fips_gcm_ghash_neon
#define _bn_GF2m_mul_2x2 _fips_bn_GF2m_mul_2x2
#define _OPENSSL_cleanse _FIPS_openssl_cleanse
#endif
#define aes_p8_encrypt fips_aes_p8_encrypt
#define aes_p8_decrypt fips_aes_p8_decrypt
#define aes_p8_set_encrypt_key fips_aes_p8_set_encrypt_key
#define aes_p8_set_decrypt_key fips_aes_p8_set_decrypt_key
#define aes_p8_cbc_encrypt fips_aes_p8_cbc_encrypt
#define aes_p8_ctr32_encrypt_blocks fips_aes_p8_ctr32_encrypt_blocks
#define aes_p8_xts_encrypt fips_aes_p8_xts_encrypt
#define aes_p8_xts_decrypt fips_aes_p8_xts_decrypt
#define gcm_init_p8 fips_gcm_init_p8
#define gcm_gmult_p8 fips_gcm_gmult_p8
#define gcm_ghash_p8 fips_gcm_ghash_p8
#define sha256_block_p8 fips_sha256_block_p8
#define sha512_block_p8 fips_sha512_block_p8
#define sha256_block_ppc fips_sha256_block_ppc
#define sha512_block_ppc fips_sha512_block_ppc
#define OPENSSL_ppccap_P fips_openssl_ppccap_p
#define OPENSSL_crypto207_probe fips_openssl_crypto207_probe

#if defined(_MSC_VER)
# pragma const_seg("fipsro$b")
# pragma const_seg()
# define __fips_constseg __declspec(allocate("fipsro$b"))
#else
# define __fips_constseg
#endif
