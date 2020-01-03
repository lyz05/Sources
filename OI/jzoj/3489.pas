var s,s1:string;
    ss:string;
    i,l,l1,max,tt1,tt2,tt3,tt4:longint;
    p:boolean;
begin
	readln(s);
	readln(ss);
	s1:='';
	l:=length(ss);l1:=length(s);
	for i:=1 to length(s) do s1:=s[i]+s1;
	p:=true;
	max:=0;
	while p do begin
		tt1:=pos(ss[1],s);
		tt2:=pos(ss[l],s1);
                if (tt1=0)or(tt2=0) then break;
		tt3:=l1-tt2+1;
		tt4:=l1-tt1+1;
		delete(s,1,tt1);
		delete(s,tt3-tt1,tt2);
		delete(s1,1,tt2);
		delete(s1,tt4-tt2,tt1);
                l1:=l1-tt1-tt2;
		for i:=2 to l-1 do begin
			if pos(ss[i],s)=0 then begin
				p:=false;
				break;
			end;
		end;
                    if not p then break;
		if max<tt1*tt2 then max:=tt1*tt2;
	end;
	writeln(max);
end.
