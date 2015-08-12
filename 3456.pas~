const	maxn=700000;mo=100000000;len=8;
type	arr=array[0..7000] of int64;
var	i,j,k,m,n:longint;
	p:array[1..maxn] of boolean;
	pri:array[0..100000] of longint;
	ans:arr;
	z:arr;
procedure prepar(n:longint);
var	i:longint;
begin
	fillchar(p,sizeof(p),true);
	for i:=2 to n do begin
		if p[i] then begin
			inc(pri[0]);
			pri[pri[0]]:=i;
			for j:=i to n div i do begin
				if p[i*j] then p[i*j]:=false;
			end;
		end;
	end;
end;
procedure cf(var x:arr;y:int64);
var	t,inp:int64;
begin
	inp:=0;
	for i:=1 to x[0] do begin
		t:=x[i]*y+inp;
		x[i]:=t mod mo;
		inp:=t div mo;
	end;
	while inp<>0 do begin
		inc(i);
		x[i]:=inp mod mo;
		inp:=inp div mo;
	end;
	x[0]:=i;
end;
procedure work;
var	i,ei,nn:longint;
	xx:int64;
begin
	ans[0]:=1;ans[1]:=1;xx:=1;
	for i:=1 to pri[0] do begin
		if pri[i]>n then break;
		ei:=0;
		nn:=n;
		while (nn<>0) do begin
			nn:=nn div pri[i];
			ei:=ei+nn;
		end;
		ei:=ei*2;
		inc(ei);
		xx:=xx*ei;
		if i=pri[0] then begin
			cf(ans,xx);
			break;
		end;
		if xx>1000000 then begin 
			cf(ans,xx);
			xx:=1;
		end;
		//ans:=ans*ei;
	end;
end;
procedure printf(ans:arr);
var	s:string;
	j:longint;
begin
	write(ans[ans[0]]);
	for i:=ans[0]-1 downto 1 do begin
		str(ans[i],s);
		for j:=1 to len-length(s) do write(0);
		write(s);
	end;
	writeln;
end;
begin
	readln(n);
	prepar(n);
	work;
	{ans[0]:=3;ans[1]:=193;ans[2]:=248;ans[3]:=7;
	cf(ans,123456);}
	printf(ans);
end.
