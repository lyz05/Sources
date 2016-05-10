uses	math;
const	pri:array[1..50] of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229);
var	i,j,t,l,r,ans,p,m:longint;
	flag:array[1..1000000] of boolean;
function fj(x:longint):longint;
var	i:longint;
begin
	for i:=1 to 50 do begin
		while x mod pri[i]=0 do begin
			x:=x div pri[i];
			fj:=pri[i];
		end;
		if x=1 then break;
	end;
	if x<>1 then fj:=x;
end;
procedure dfs(dep,a,b:longint);
var	i:longint;
begin
	if dep>p then exit;
	if (l<=a) and (a<=r) and (flag[a]) then begin
		inc(ans);
		flag[a]:=false;
	end;
	for i:=0 to 1 do begin
		if odd(i) then dfs(dep+1,a,b+1) else dfs(dep+1,a*b,b);
	end;
end;
begin
	ans:=0;
	//prepar;
	readln(l,r,p);
	if (p<=25) and (r<=1000000) then begin
	fillchar(flag,sizeof(flag),true);
	if p<=2 then ans:=0 else dfs(2,1,2);
	end else begin
	for i:=l to r do begin
		t:=fj(i);
		m:=i div fj(i);
		j:=1;
		while power(m,1/j)>t do inc(j);
		if t=i then j:=0;
		inc(j);
		if t+j<=p then begin
			inc(ans);
		end;
	end;
	end;
	writeln(ans);
end.
