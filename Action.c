Action()
{
	int i;
	char* s;
	char *dCity;
	char *aCity;
	char * fName;
	char * lName;
	char * seatf;
	char * typef;
	int random;
	s=lr_eval_string("{ticketCount}");
	random=atoi(s);
	
	
	for (i=1;i<=random;i++) {
		
			dCity=lr_eval_string("{city}");
	aCity=lr_eval_string("{city2}");
	fName=lr_eval_string("{name}");
	lName=lr_eval_string("{lastname}");
	seatf=lr_eval_string("{seat}");
	typef=lr_eval_string("{type}");
	
	lr_save_string(dCity,"dCity");
	lr_save_string(aCity,"aCity");
	lr_save_string(fName,"fName");
	lr_save_string(lName,"lName");
	lr_save_string(seatf,"seatf");
	lr_save_string(typef,"typef");
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		
	web_reg_save_param_ex(
    "ParamName=ofFlight", 
    "LB/IC=name=\"outboundFlight\" value=\"",
    "RB/IC=\"",
    "Ordinal=1",
	LAST);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={dCity}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={aCity}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatf}", ENDITEM, 
		"Name=seatType", "Value={typef}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=62", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);
		
		lr_output_message("%s",lr_eval_string("{dCity}"));
			lr_output_message("%s",lr_eval_string("{departDate}"));
				lr_output_message("%s",lr_eval_string("{aCity}"));
					lr_output_message("%s",lr_eval_string("{returnDate}"));
						lr_output_message("%s",lr_eval_string("{seatf}"));
							lr_output_message("%s",lr_eval_string("{typef}"));

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={ofFlight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={typef}", ENDITEM, 
		"Name=seatPref", "Value={seatf}", ENDITEM, 
		"Name=reserveFlights.x", "Value=56", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);


	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={fName}", ENDITEM, 
		"Name=lastName", "Value={lName}", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value={fName} {lName}", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={typef}", ENDITEM, 
		"Name=seatPref", "Value={seatf}", ENDITEM, 
		"Name=outboundFlight", "Value={ofFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=32", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		LAST);
							
							lr_output_message("%s",lr_eval_string("{fName}"));
			lr_output_message("%s",lr_eval_string("{lName}"));
	
	}
	return 0;
}