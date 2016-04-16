var	i,j,k,l,m,n,ts,tt,ans:longint;
	s,t:array[1..500] of ansistring;		//change
	ss,s1,s2:ansistring;			//change
function judge(s1,s2:ansistring):boolean;
var	i,j,k,jj:longint;
	flag:boolean;
begin
	i:=1;j:=1;
	while (true) do begin
		while (j<=l) and (s2[j]<>s1[i]) do inc(j);
		jj:=j;
		if (j>l) then exit(false);
		flag:=true;
		for k:=1 to l do begin
			i:=i mod l+1;j:=j mod l+1;
			if (s1[i]<>s2[j]) then begin
				flag:=false;
				break;
			end;
		end;
		if flag then exit(flag);
		j:=jj+1;i:=1;
	end;
	exit(false);
end;
begin
	assign(input,'4126.in');reset(input);
	readln(ts,tt,n,m);
	for i:=1 to ts do readln(s[i]);
	for i:=1 to tt do readln(t[i]);
	l:=(n+m)>>1;
	for i:=1 to ts do 
		for j:=1 to tt do begin
			ss:=s[i]+t[j];
			s1:=copy(ss,1,l);
			s2:=copy(ss,l+1,l);
			if judge(s1,s2) then inc(ans);
		end;

	writeln(ans);
end.
