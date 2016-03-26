const	maxn=100;maxm=100000;
var	i,j,ans,tot,n,m:longint;
	s,s1,s2:ansistring;		//change
	a:array[1..maxn,-1..maxm] of longint;//neicun
procedure work(s:ansistring);
var	i:longint;
	st:ansistring;
begin
	if s='' then exit;
	inc(tot);
	st:='';
	for i:=1 to length(s) do st:=st+s2[i];
	for i:=1 to length(s2)-length(s)+1 do begin
		if st=s then begin
			inc(a[tot,0]);
			a[tot,a[tot,0]]:=i;
		end;
		delete(st,1,1);
		st:=st+s2[i+m];
	end;
end;
procedure search;
var	i,j,l,r,last:longint;
begin
	l:=1;r:=m;
	while (l<m) do begin
		last:=l;
		for j:=1 to tot do begin
			i:=1;
			while (a[j,i]<=r) and (a[j,i]<last) do inc(i);
			if (j=1) and (s2[1]<>'*') and (a[j,i]<>l) then
				break;
			if (j=tot) and (s2[m]<>'*') then begin
				while (a[j,i]<r) do inc(i);
				if a[j,i]<>r then break;
			end;
			if a[j,i]>r then break;
			last:=a[j,i];
			if j=tot then inc(ans); 
		end;

		inc(l);inc(r);
	end;
end;
begin
	assign(input,'3427.in');reset(input);
	readln(s1);
	readln(s2);
	m:=length(s2);
	s2:=s2+s2;
	i:=1;
	while i<length(s1) do begin
		if (s1[i]='*') and (s1[i+1]='*') then 
			delete(s1,i+1,1)
		else
			inc(i);
	end;
	n:=length(s1);
	s:='';
	for i:=1 to n+1 do begin
		if (s1[i]='*') or (i=n+1) then begin
			work(s);
			s:='';
		end else s:=s+s1[i];
	end;
	search;
	writeln(ans);
end.
