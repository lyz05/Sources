const	maxn=3000+5;
var	i,j,k,m,n,a,b:longint;
	ansa,ansb,sb,sa:extended;
	s:array[0..maxn,0..maxn] of extended;
begin
	readln(n,a,b);
	ansa:=0;ansb:=0;

	fillchar(s,sizeof(s),0);
	s[0,0]:=1;
	inc(a);
	for i:=0 to a do begin
		if i+1>n then break;
		for j:=0 to b do begin
			if i+j+1>n then break;
			sa:=a-i;sb:=b-j;
			if i>0 then s[i,j]:=s[i-1,j]*2*sa/(2*sa+sb+2);
			if j>0 then s[i,j]:=s[i,j]+s[i,j-1]*1*(sb+1)/(2*sa+sb+1);
			if i<a then ansa:=ansa+2/(2*sa+sb)*s[i,j];
		end;
	end;

	fillchar(s,sizeof(s),0);
	s[0,0]:=1;
	dec(a);
	inc(b);
	for i:=0 to a do begin
		if i+1>n then break;
		for j:=0 to b do begin
			if i+j+1>n then break;
			sa:=a-i;sb:=b-j;
			if i>0 then s[i,j]:=s[i-1,j]*2*(sa+1)/(2*sa+sb+2);
			if j>0 then s[i,j]:=s[i,j]+s[i,j-1]*1*sb/(2*sa+sb+1);
			if j<b then ansb:=ansb+1/(2*sa+sb)*s[i,j];
		end;
	end;
	writeln(ansa:0:16);
	writeln(ansb:0:16);

end.
