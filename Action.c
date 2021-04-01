Action()
{
	int i;
	char* s;
	int random;
	s=lr_eval_string("{ticketCount}");
	random=atoi(s);
	
	for (i=1;i<=random;i++) {
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
		"Name=depart", "Value={city}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={city2}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seat}", ENDITEM, 
		"Name=seatType", "Value={type}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=62", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);
		
		lr_output_message("%s",lr_eval_string("{city}"));
			lr_output_message("%s",lr_eval_string("{departDate}"));
				lr_output_message("%s",lr_eval_string("{city2}"));
					lr_output_message("%s",lr_eval_string("{returnDate}"));
						lr_output_message("%s",lr_eval_string("{seat}"));
							lr_output_message("%s",lr_eval_string("{type}"));

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
		"Name=seatType", "Value={type}", ENDITEM, 
		"Name=seatPref", "Value={seat}", ENDITEM, 
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
		"Name=firstName", "Value={name}", ENDITEM, 
		"Name=lastName", "Value={lastname}", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value={name} {lastname}", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={type}", ENDITEM, 
		"Name=seatPref", "Value={seat}", ENDITEM, 
		"Name=outboundFlight", "Value={ofFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=32", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		LAST);
							
							lr_output_message("%s",lr_eval_string("{name}"));
			lr_output_message("%s",lr_eval_string("{lastname}"));
	
	}
	return 0;
}