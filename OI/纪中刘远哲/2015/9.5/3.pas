const	maxn=60;mo=258280327;
var	i,j,k,n,T,ans:longint;
	m:int64;
	s:array[1..maxn] of ansistring;		//change
function work(s:ansistring):longint;		//change
var	i:longint;
	flag:boolean;
begin
	//ans:=0;
	//st:=s;
	for i:=2 to m do begin
		flag:=true;
		for j:=i to m do
			if s[j]<>s[j-i+1] then begin
				flag:=false;
				break;
			end;
		if flag then exit(m-i+1);
	end;
	exit(0);
end;
begin
	//assign(input,'3.in');reset(input);
	readln(T);
	s[1]:='a';s[2]:='b';
	while T<>0 do begin
		readln(n,m);
		if m=1 then begin
			writeln(0);
			dec(T);
			continue;
		end;
		for i:=3 to n do begin
			if s[i]='' then s[i]:=s[i-1]+s[i-2];
			if length(s[i])>m then break;
		end;
		ans:=work(copy(s[i],1,m)) mod mo;
		writeln(ans);
		//for i:=1 to n do writeln(s[i]);

		dec(T);
	end;
end.
