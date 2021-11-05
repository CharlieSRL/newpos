vuser_init()
{
	//{"accessToken":{"token":"ADToken MzU0MGUwZjEtNWZjOC00ZWQ2LWE5MWUtZTFkNjVmMWM2ZDU5OjIwMTcxMjIxMDIyODE2",
  
	web_reg_save_param("authorization", "LB=token\":\"","RB=\",","ORD=1",LAST);
	
	web_set_sockets_option("SSL_VERSION","TLS1.2");	
	web_cache_cleanup();
	web_cleanup_cookies();
	
	lr_start_transaction("01_Login");	

	web_custom_request("web_custom_request",
		
		"URL=https://{Environment}.rei.com/NCRRetailOne/api/v8/Security/Login",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTTP",
		"EncType=application/json; charset=UTF-8", 
		"Body={\"orgName\":\"Corporate\",\"userName\":\"{Param_Username}\",\"password\":\"{Param_Password}\"}",
		LAST);

	lr_end_transaction("01_Login", LR_AUTO);
	return 0;
}
