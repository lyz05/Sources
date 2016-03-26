const	maxn=100000;
var	i,j,k,m,n:longint;
	pri,fri:array[0..maxn] of longint;
        p:array[1..maxn] of boolean;
	ans:int64;
begin
	readln(n);
	if n=1 then begin
		writeln(0);
		exit;
	end;
	for i:=2 to n do begin
		if not p[i] then begin
			inc(pri[0]);
			pri[pri[0]]:=i;
			fri[i]:=i-1;
		end;
		for j:=1 to pri[0] do begin
			if i*pri[j]>n then break;
			if i mod pri[j]=0 then
				fri[i*pri[j]]:=fri[i]*(fri[pri[j]]+1)
			else fri[i*pri[j]]:=fri[i]*fri[pri[j]];
		end;
	end;
	ans:=0;
	for i:=2 to n-1 do
		inc(ans,fri[i]);
	ans:=ans*2+3;
	writeln(ans);
end.
