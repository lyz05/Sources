const	maxn=100;maxm=100;		//区分大小写
type	node=record
		x,y,cnt:longint;
	end;
var	i,j,k,m,n,x,len,ans,t,minn:longint;
	s:string;
	map:array[1..maxn,1..maxm] of char;
	cnt:array[1..maxn,1..maxm] of longint;
	inf:array[1..52,1..maxn*maxm,1..2] of longint;
	tot:array[1..52] of longint;
	flag:boolean;
function min(x,y:longint):longint;
begin
	if x>y then min:=y else min:=x;
end;
procedure dfs(dep,tx,ty:longint);
var	i,id,x,y:longint;
begin
	if dep>len then begin
		inc(ans,minn);
		flag:=true;
		exit;
	end;
	id:=ord(s[dep])-64;
	if id>26 then id:=ord(s[dep])-96+26;

	for i:=1 to tot[id] do begin
		x:=inf[id,i,1];y:=inf[id,i,2];
		if (cnt[x,y]>0) and ((abs(x-tx)<=1) and (abs(y-ty)<=1) or (dep=1))
		then begin
			minn:=min(minn,cnt[x,y]);
			//flag:=false;
			//dec(cnt[x,y]);
			tx:=x;ty:=y;
				dfs(dep+1,x,y);
			if flag then begin
				dec(cnt[x,y],minn);
				exit;
			end;
			//if not flag then inc(cnt[x,y]) else exit;
		end;
	end;
end;
begin
	assign(input,'wordcount.in');reset(input);
	assign(output,'wordcount.out');rewrite(output);
		
	readln(t);
	for k:=1 to t do begin
		fillchar(tot,sizeof(tot),0);
		ans:=0;
		readln(n,m);
		for i:=1 to n do begin
			readln(s);
			for j:=1 to m do begin
				map[i,j]:=s[j];
				x:=ord(s[j])-64;
				if x>26 then x:=ord(s[j])-96+26;
				inc(tot[x]);
				inf[x,tot[x]][1]:=i;
				inf[x,tot[x]][2]:=j;
			end;
		end;
		for i:=1 to n do begin
			for j:=1 to m do begin
				read(x);
				cnt[i,j]:=x;
			end;
		end;

		readln;
		readln(s);
		len:=length(s);
		repeat
			flag:=false;
			minn:=maxlongint>>1;
			dfs(1,0,0);
		until not flag;
		writeln('Case #',k,': ',ans);
	end;

	close(input);close(output);
end.
