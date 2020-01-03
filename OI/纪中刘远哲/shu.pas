const maxn=500;maxk=15;
var 	i,j,n,m,k,t,tmp,min,x,y,z,minn,ans,kk,maxkk,minans:longint;
	map:array[1..maxn,1..maxn] of integer;
	p:array[1..maxn] of boolean;
	num:array[1..maxk] of longint;
procedure dfs(deep,x,y:longint);
var i:longint;
begin
	if deep>n then exit;
	if x=y then begin
		if tmp<min then min:=tmp;
		exit;
	end;
	for i:=1 to n do begin
		if (map[x,i]<>0) and not p[i] then begin
			p[i]:=true;
			inc(tmp,map[x,i]);
				dfs(deep+1,i,y);
			dec(tmp,map[x,i]);
			p[i]:=false;
		end;
	end;
end;
procedure dfs1(deep,x,y:longint);
var i:longint;
begin
	if deep>n then exit;
	if x=y then begin
		if t>=tmp+minn then begin
			kk:=0;
			for i:=1 to k do
				if p[num[i]] then inc(kk);
			if (kk>=maxkk) and (tmp<minans) then begin
				maxkk:=kk;
				minans:=tmp;
			end;
		end;
	end;
	for i:=1 to n do begin
		if (map[x,i]<>0) and not p[i] then begin
			p[i]:=true;
			inc(tmp,map[x,i]);
				dfs1(deep+1,i,y);
			dec(tmp,map[x,i]);
			p[i]:=false;
		end;
	end;
end;
procedure print(s:string);
begin
	writeln(s);
	halt;
end;
procedure print1(x,y:longint);
begin
	writeln(x,' ',y);
	halt;
end;
function zdl(x,y:longint):longint;
begin
	min:=maxlongint;
        tmp:=0;
	dfs(1,x,y);
	zdl:=min;
end;
begin
assign(input,'shu.in');reset(input);
assign(output,'shu.out');rewrite(output);
	
        readln(n,m,k,t);
	for i:=1 to m do begin
		readln(x,y,z);
		map[x,y]:=z;
		map[y,x]:=z;
	end;
	for i:=1 to k do read(num[i]);
	p[1]:=true;
	minn:=zdl(1,n);
	if minn*2>t then print('-1');
	if k=0 then print1(0,minn*2);
	if k<=2 then begin
		ans:=0;
		kk:=k;
		for i:=1 to k do begin
			tmp:=zdl(1,num[i])+zdl(num[i],n);
			if tmp+minn>t then dec(kk) else ans:=ans+tmp;
		end;
		if kk=0 then print1(0,minn*2);
		if (k=2) and (kk=2) then print1(kk,ans);
		if kk=1 then print1(kk,ans+minn);
	end;
	maxkk:=0;minans:=maxlongint;
	dfs1(1,1,n);
        minans:=minans+minn;
	print1(maxkk,minans);

close(input);close(output);
end.
