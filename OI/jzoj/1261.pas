const	maxn=20;
var	i,j,k,n,m:longint;
	c:array[1..maxn,1..maxn] of longint;
	v:array[1..maxn] of boolean;
	a,cc,vv:array[0..maxn] of longint;
	flag:boolean;
procedure prepar;
var	i,j:longint;
begin
	c[1,1]:=1;
	for i:=2 to maxn do begin
		for j:=1 to i do c[i,j]:=c[i-1,j]+c[i-1,j-1];	
	end;
end;
function judge(dep,t,ii:longint):boolean;
var	i,j,l,sum:longint;
begin
	fillchar(cc,sizeof(cc),0);
	for i:=dep+1 to n do 
		cc[i-dep]:=c[n,i];
	l:=n-dep;
	for i:=1 to l-1 do
		for j:=i+1 to l do 
			if cc[i]>cc[j] then begin
				cc[0]:=cc[i];
				cc[i]:=cc[j];
				cc[j]:=cc[0];
			end;
	vv[0]:=0;
	for i:=1 to n do
		if not v[i] then begin
			inc(vv[0]);
			vv[vv[0]]:=i;
		end;
	sum:=0;
	for i:=1 to l do
	       sum:=sum+cc[i]*vv[i];
	if sum+t+ii*c[n,dep]<m then exit(false);
	//能达到的最大值
	sum:=0;
	for i:=1 to l do 
		sum:=sum+cc[i]*vv[l-i+1];
	if sum+t+ii*c[n,dep]>m then exit(false);
0	//能达到的最小值
	exit(true);
	//能够达到的最大最小值优化
end;
procedure dfs(dep,t:longint);
var	i,st:longint;
begin
	
	if dep>n then begin
		if t=m then begin
			flag:=true;
			for i:=1 to n-1 do write(a[i],' ');
			writeln(a[n]);
		end;
		exit;
	end;
	if (dep>(n+1) div 2) then st:=a[n-dep+1]+1 else st:=1;
	//杨辉三角对称性优化，有序性
	for i:=st to n do begin
		if (not v[i]) and (i*c[n,dep]+t<=m) then begin
			v[i]:=true;
			a[dep]:=i;
			if judge(dep,t,i) then
				dfs(dep+1,t+c[n,dep]*i);
			a[dep]:=0;
			v[i]:=false;
			if flag then exit;
		end;
	end;
end;
begin
	assign(input,'easy.in');reset(input);
	//assign(output,'easy.out');rewrite(output);

	prepar;
	while true do begin
		//if eof then break;
		readln(n,m);
		if (n=0) and (m=0)then break;
		flag:=false;
		dfs(1,0);
	end;
	//close(input);close(output);

end.
