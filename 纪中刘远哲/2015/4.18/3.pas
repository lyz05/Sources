const	maxk=16;
type	arr=array[1..maxk] of longint;
var	i,j,k,m,n,len,ans:longint;
	s:string;		//change
	ch:char;
	flag:array[1..maxk] of boolean;
	a:arr;
procedure work(a:arr);
var	i,j,t,cnt:longint;
begin
	ch:=' ';t:=1;cnt:=0;
	for i:=1 to len do begin
		if ch<>s[a[t]] then inc(cnt);
		ch:=s[a[t]];
		inc(t);
		if t>k then dec(t,k);
		if i mod k=0 then 
			for j:=1 to k do inc(a[j],k);
	end;
	if cnt<ans then ans:=cnt;
end;
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>k then begin
		work(a);
		exit;
	end;
	for i:=1 to k do begin
		if not flag[i] then begin
			flag[i]:=true;
			a[dep]:=i;
				dfs(dep+1);
			a[dep]:=0;
			flag[i]:=false;
		end;
	end;
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(k);
	readln(s);
	len:=length(s);
	ans:=maxlongint>>1;
	dfs(1);
	writeln(ans);
end.
