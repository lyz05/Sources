var	ans,k,anss:longint;
begin
	randomize;
	anss:=0;
	while true do begin
	
	ans:=0;k:=0;
	while true do begin
		if ans>=3 then break;
		k:=random(2);
		case k of 
			0:inc(ans,1);
			1:inc(ans,2);
		end;
	end;
	if ans>3 then dec(ans,2);
	
	if ans>anss then begin
		anss:=ans;
		writeln(anss);
	end;
	end;
end.
