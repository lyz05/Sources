const maxpd=31622;
var	i,j,k,m,n,t,len:longint;
	a:array[1..1000,1..2] of longint;
	p:array[1..1000] of longint;
	pri:array[0..5431] of longint;
	pd:array[1..maxpd] of boolean;
     ans,tot:int64;
function oula(n:longint):longint;
var      i:longint;
begin
	   if n=1 then exit(0);
        i:=2;
        oula:=n;
        while i*i<=n do begin
                if n mod i=0 then begin
                        oula:=oula div i*(i-1);
                        while n mod i=0 do n:=n div i;
                end else inc(i);
        end;
        if n<>1 then oula:=oula div n*(n-1);
end;
procedure dfs(deep:longint);
var i,j:longint;
begin
	if deep>len then begin
		tot:=1;
		for i:=1 to len do
			for j:=1 to p[i] do tot:=tot*a[i,1];
		ans:=ans+tot*oula(tot) div 2;
		if tot=1 then inc(ans);
		exit;
	end else begin
		for i:=0 to a[deep,2] do begin
                        p[deep]:=i;
			dfs(deep+1);
                        p[deep]:=0;
		end;
	end;
end;
procedure prepare;
begin
	for i:=2 to maxpd do
		if not pd[i] then begin
			inc(pri[0]);
			pri[pri[0]]:=i;
			for j:=i*i to maxpd div i do
				pd[i*j]:=true;
		end;
end;
begin
	prepare;
	readln(t);
	for j:=1 to t do begin
		read(n);
		len:=0;
		ans:=0;
		fillchar(a,sizeof(a),0);
		for i:=1 to pri[0] do begin
			if n mod pri[i]=0 then begin
				inc(len);
				a[len,1]:=pri[i];
				while n mod pri[i]=0 do begin
					inc(a[len,2]);
					n:=n div pri[i];
				end;
				if n=1 then break;
			end;
		end;
		if n>1 then begin
			inc(len);
			a[len,1]:=n;
			a[len,2]:=1;
		end;
		dfs(1);
		writeln(ans);
	end;
end.
