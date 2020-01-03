const   maxn=2000;maxl=1000;
        mo=maxn*maxl;
        minmo=999973;maxmo=49999931;
type node=record
		h1,h2,cnt,num:longint;
	end;
var	n,m,i,j,k,l,ans:longint;
	s:array[1..maxn] of ansistring;
	h:array[0..mo+1] of node;
procedure add(x,h1,h2,tot:longint);
begin
     h[tot].h1:=h1;
	h[tot].h2:=h2;
	h[tot].cnt:=1;
	h[tot].num:=x;
end;
procedure hash(x,h1,h2:longint);
var ti:longint;
begin
	ti:=h1 mod mo;
	while true do begin
		if (h2=h[ti].h2) and (h1=h[ti].h1) then begin
			if (h[ti].num=x) then exit;
			h[ti].num:=x;
			inc(h[ti].cnt);
			exit;
		end;
		if h[ti].num=0 then break;
		if ti=mo then ti:=-1;
          inc(ti);
	end;
	add(x,h1,h2,ti);
end;
procedure work;
var k1,k2,h1,h2,i,j,k:longint;
begin
	k1:=1;k2:=1;
	for i:=1 to l-1 do begin
		k1:=(k1*26) mod minmo;
		k2:=(k2*26) mod maxmo;
	end;
	for i:=1 to n do begin
		h1:=0;h2:=0;
		for k:=1 to l do begin
			h1:=(h1*26+ord(s[i][k])-ord('a')+1) mod minmo;
			h2:=(h2*26+ord(s[i][k])-ord('a')+1) mod maxmo;
		end;
		hash(i,h1,h2);
		for j:=l+1 to length(s[i]) do begin
			h1:=((h1-(ord(s[i][j-L])-ord('a')+1)*k1) mod MinMo+MinMo) mod MinMo;
			h2:=((h2-(ord(s[i][j-L])-ord('a')+1)*k2) mod MaxMo+MaxMo) mod MaxMo;
			h1:=(h1*26+(ord(s[i][j])-ord('a')+1)) mod MinMo;
			h2:=(h2*26+(ord(s[i][j])-ord('a')+1)) mod MaxMo;
			hash(i,h1,h2);
		end;
	end;

end;
begin
        //assign(input,'3870.in');reset(input);
        readln(n,m,l);
	for i:=1 to n do readln(s[i]);
	work;
	ans:=0;
	for i:=0 to mo do
		if h[i].cnt>=m then inc(ans);
	writeln(ans);
end.
