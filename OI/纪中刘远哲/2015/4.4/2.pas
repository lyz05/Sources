const	maxlen=1000;minmo=39041;maxmo=49993;maxn=(1000*1001) div 2;
	alpha='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
type	arr=array[0..maxn] of ansistring;
	node=record
		h1,h2:longint;
	end;
var	i,j,k,len,tot,h1,h2:longint;
	a:arr;
	h:array[0..maxn] of node;
	s,s1:ansistring;
	//change
procedure qsort(var a1:arr;l,r:longint);
var	i,j:longint;
	m:ansistring;
begin
	m:=a1[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while a1[i]<m do inc(i);
		while a1[j]>m do dec(j);
		if i<=j then begin
			a1[0]:=a1[i];
			a1[i]:=a1[j];
			a1[j]:=a1[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(a1,l,j);
	if i<r then qsort(a1,i,r);
end;
function add(h1,h2:longint):boolean;
var	i:longint;
begin
	i:=h1 mod maxn;
	while true do begin
		if h[i].h1=0 then begin
			h[i].h1:=h1;
			h[i].h2:=h2;
			exit(true);
		end;
		if (h[i].h1=h1) and (h[i].h2=h2) then exit(false);
		i:=(i+1) mod maxn;
	end;
end;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(s);
	readln(k);
	len:=length(s);tot:=0;
	for i:=1 to len do begin
		s1:='';h1:=0;h2:=0;
		for j:=i to len do begin
			s1:=s1+s[j];
			h1:=((h1*52+pos(s[j],alpha)) mod minmo);
			h2:=((h2*52+pos(s[j],alpha)) mod maxmo);
			if add(h1,h2) then begin
				inc(tot);
				a[tot]:=s1;
			end;
		end;
	end;
	qsort(a,1,tot);
	writeln(a[k]);
end.
