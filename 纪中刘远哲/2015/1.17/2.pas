const	maxn=10000+10;mo=1000000;maxmo=49999931;minmo=999973;
type	node=record
		h1,h2,cnt:longint;
	end;
var	n,i,k,ans:longint;
	s:array[1..maxn] of ansistring;	//change
	h:array[0..mo] of node;
	p:array[0..mo] of boolean;
procedure add(tot,h1,h2:longint);
begin
	p[tot]:=true;
	h[tot].h1:=h1;
	h[tot].h2:=h2;
	h[tot].cnt:=1;
end;
procedure hash(h1,h2,kk:longint);
var	ti:longint;
begin
	ti:=h1 mod mo;
	while true do begin
		if (h2=h[ti].h2) and (h1=h[ti].h1) then begin
			if kk=1 then begin
				if not p[ti] then inc(h[ti].cnt)
			end else
				if h[ti].cnt>=k then inc(ans);
			p[ti]:=true;
			exit;
		end;
		if h[ti].cnt=0 then break;
		ti:=(ti+1) mod mo;
	end;
	add(ti,h1,h2);
end;
procedure work(s:string;kk:longint);
var	i,j,len,h1,h2,tmp:longint;
begin
	if kk=1 then fillchar(p,sizeof(p),false);
	len:=length(s);
	for i:=1 to len do begin
		h1:=0;h2:=0;
		for j:=i to len do begin
			tmp:=ord(s[j])-ord('a')+1;
			h1:=(h1*26+tmp) mod minmo;
			h2:=(h2*26+tmp) mod maxmo;
			hash(h1,h2,kk);
		end;
	end;
end;
begin
	assign(input,'2.in');reset(input);
	assign(output,'2.out');rewrite(output);

	readln(n,k);
	for i:=1 to n do begin
		readln(s[i]);
		work(s[i],1);
	end;
	for i:=1 to n do begin
		ans:=0;
		work(s[i],2);
		write(ans,' ');
	end;
end.
