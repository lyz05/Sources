uses	math;
const	maxk=6+3;maxn=200+2;
var	i,j,k,kk,m,n,p,path,t:longint;
	s,s1:string;
	word:array[1..maxk] of string;
	f:array[0..maxn,0..maxn,0..40+1] of longint;
	sum:array[0..maxn,0..maxn] of longint;
procedure check(x,y:longint);
var	i,j:longint;
begin
	for i:=1 to length(word[y]) do 
		if s[x+i-1]<>word[y][i] then begin
			exit;
		end;
	{
	for i:=1 to x do begin
		inc(f[i][x+length(word[y])-1][0]);
		//sum[i][x+length(word[y])-1]:=f[i][x+length(word[y])-1][0];
	end;
	for i:=x+length(word[y])-1 to n do begin
		inc(f[x][i][0]);
		//sum[x][i]:=f[x][i][0];
	end;
	}
	for i:=1 to x do begin
		for j:=x+length(word[y])-1 to n do begin
			inc(f[i][j][1]);
		end;
	end;
end;
begin
	//assign(input,'1118.in');reset(input);

	readln(p,path);
	for i:=1 to p do begin
		readln(s1);
		s:=s+s1;
	end;
	readln(k);
	for i:=1 to k do begin
		readln(word[i]);
		for j:=1 to i-1 do 
			if word[i]=word[j] then word[i]:=' ';
	end;
	fillchar(f,sizeof(f),0);
	n:=length(s);
	for i:=1 to n do 
		for j:=1 to k do 
			if (i+length(word[j])<=n+1) then check(i,j);
	for t:=2 to path do 
		for i:=1 to n do 
			for j:=i+1 to n do 
				for kk:=i+1 to j-1 do 
				f[i][j][t]:=max(f[i][j][t],f[i][kk][t-1]+f[kk+1][j][t-1]);
	writeln(f[1][n][path]);
end.
