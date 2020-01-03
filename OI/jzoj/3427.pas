const	maxn=100;maxm=100000;
var	s1:string;
	s2:ansistring;
	n,m,i,ans:longint;
	flag,flag1:boolean;
	next:array[1..2*maxn] of longint;
	pos:array[1..maxn,0..2*maxm] of longint;
	f:array[1..maxn] of longint;
	st:array[1..maxn] of string;
procedure work;
var	i:longint;
begin
	if (s1[1]<>'*') then flag:=true;
	if (s1[length(s1)]<>'*') then flag1:=true;
	for i:=1 to length(s1) do 
		if (s1[i]<>'*') then begin
			if i=1 then begin
				inc(n);
				st[n]:=s1[i];
				continue;
			end;
			if s1[i-1]='*' then begin
				inc(n);
				st[n]:=s1[i];
			end else
				st[n]:=st[n]+s1[i];
		end;
end;
procedure prepar(x:longint);
var	s:string;
	i,j:longint;
begin
	fillchar(next,sizeof(next),0);
	s:=st[x];
	j:=0;next[1]:=0;
	for i:=2 to length(s) do begin
		while (j>0) and (s[j+1]<>s[i]) do j:=next[j];
		if s[j+1]=s[i] then inc(j);
		next[i]:=j;
	end;
	j:=0;
	for i:=1 to length(s2) do begin
		while (j>0) and (s[j+1]<>s2[i]) do j:=next[j];
		if s[j+1]=s2[i] then inc(j);
		if j=length(s) then begin
			inc(pos[x][0]);
			pos[x][pos[x][0]]:=i-length(s)+1;
			j:=next[j];
		end;
	end;
end;
function judge(left:longint):boolean;
var	i:longint;
begin
	for i:=1 to n do begin
		while (f[i]=0) or (pos[i][f[i]]<left) or (i>1) and 
		(pos[i][f[i]]<=pos[i-1][f[i-1]]+length(st[i-1])-1) do begin
			if (f[i]=pos[i][0]) then begin
				f[i]:=0;
				exit(false);
			end;
			inc(f[i]);
		end;
		if (pos[i][f[i]]+length(st[i])-1>left+m-1) then exit(false);
		if flag and (pos[1][f[1]]>left) then exit(false);
	end;
	if flag1 then begin
		while (pos[n][f[n]]+length(st[n])-1 < left+m-1) do begin
			if (f[n]=pos[i][0]) then begin
				f[i]:=0;
				exit(false);
			end;
			inc(f[i]);
		end;
		if (pos[n][f[n]]+length(st[n])-1 > left+m-1) then exit(false);
	end;
	exit(true);
end;
begin
	assign(input,'3427.in');reset(input);
	flag:=false;
	flag1:=false;
	readln(s1);
	work;
	readln(s2);
	m:=length(s2);
	s2:=s2+s2;delete(s2,length(s2),1);
	for i:=1 to n do
		prepar(i);
	ans:=0;
	for i:=1 to m do 
		if judge(i) then inc(ans);
	writeln(ans);
end.
