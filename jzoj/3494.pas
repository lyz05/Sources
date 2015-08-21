const	maxn=20000+2;mo=1000000007;hamo=200000+2;
type	node=record
		v,ad,ad2:longint;
	end;
	arr=array[1..2*maxn] of longint;
var	i,n,sum,ret,x,y,z,t,kk:longint;
	q:array[1..maxn,1..4] of longint;
	h:array[1..hamo] of node;
	a:arr;
	len,d:array[1..hamo] of longint;
	hash:array[0..hamo,1..2] of longint;
procedure times(var x:longint;y:longint);
begin
	x:=(int64(x) * (y mod mo)) mod mo;
end;
function pow(x:int64;y:longint):int64;
begin
	pow:=1;
	while y<>0 do begin
		if odd(y) then pow:=(pow*x) mod mo;
		x:=(x*x) mod mo;
		y:=y>>1;
	end;
end;
procedure qsort(var a1:arr;l,r:longint);
var	m,i,j,t:longint;
begin
	m:=a1[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while a1[i]<m do inc(i);
		while a1[j]>m do dec(j);
		if i<=j then begin
			t:=a1[i];
			a1[i]:=a1[j];
			a1[j]:=t;
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(a1,l,j);
	if i<r then qsort(a1,i,r);
end;

procedure maketree(x,l,r:longint);
var	mid:longint;
begin
	if (l=r) then begin
		h[x].v:=1;
		h[x].ad:=1;
		h[x].ad2:=1;
		d[x]:=len[l];
	end else begin
		mid:=(l+r) >> 1;
		maketree(x*2,l,mid);
		maketree(x*2+1,mid+1,r);
		h[x].v:=1;
		d[x]:=d[x*2]+d[x*2+1];
		h[x].ad:=1;
		h[x].ad2:=1;
	end;
end;
procedure change(x,l,r:longint);
begin
        h[x*2].v	:=pow(h[x*2].v,h[x].ad2);
        h[x*2+1].v	:=pow(h[x*2+1].v,h[x].ad2);
        h[x*2].ad	:=pow(h[x*2].ad,h[x].ad2);
        h[x*2+1].ad	:=pow(h[x*2+1].ad,h[x].ad2);
        h[x*2].ad2	:=(int64(h[x*2].ad2) * h[x].ad2) mod (mo-1);
        h[x*2+1].ad2	:=(int64(h[x*2+1].ad2) * h[x].ad2) mod (mo-1);
        h[x].ad2	:=1;

        times(h[x*2].v,pow(h[x].ad,d[x*2]));
        times(h[x*2].ad,h[x].ad);
	times(h[x*2+1].v,pow(h[x].ad,d[x*2+1]));
        times(h[x*2+1].ad,h[x].ad);
        h[x].ad := 1;
end;
procedure modify1(x,l,r,st,en,w:longint);
var	mid:longint;
begin
	if (st<=l) and (r<=en) then begin
		times(h[x].v,pow(w,d[x]));
		times(h[x].ad,w);
	end else begin
		change(x,l,r);
		mid:=(l+r) >> 1;
		if en<=mid then modify1(x*2,l,mid,st,en,w)
		else if st>mid then modify1(x*2+1,mid+1,r,st,en,w)
		else begin
			modify1(x*2,l,mid,st,mid,w);
			modify1(x*2+1,mid+1,r,mid+1,en,w);
		end;
		h[x].v:=(int64(h[x*2].v) * h[x*2+1].v) mod mo;
	end;
end;
procedure modify2(x,l,r,st,en,w:longint);
var	mid:longint;
begin
	if (st<=l) and (r<=en) then begin
                h[x].v := pow(h[x].v,w);
                h[x].ad := pow(h[x].ad,w);
                h[x].ad2 := (int64(h[x].ad2) * w) mod (mo-1);
	end else begin
		change(x,l,r);
		mid:=(l+r) >> 1;
		if en<=mid then modify2(x*2,l,mid,st,en,w)
		else if st>mid then modify2(x*2+1,mid+1,r,st,en,w)
		else begin
			modify2(x*2,l,mid,st,mid,w);
			modify2(x*2+1,mid+1,r,mid+1,en,w);
		end;
		h[x].v:=(int64(h[x*2].v) * h[x*2+1].v) mod mo;
	end;
end;
procedure query(x,l,r,st,en:longint);
var	mid:longint;
begin
	if (st<=l) and (r<=en) then begin
		times(ret,h[x].v);
	end else begin
		change(x,l,r);
		mid:=(l+r) >> 1;
		if en<=mid then query(x*2,l,mid,st,en)
		else if st>mid then query(x*2+1,mid+1,r,st,en)
		else begin
			query(x*2,l,mid,st,mid);
			query(x*2+1,mid+1,r,mid+1,en);
		end;
		h[x].v:=(int64(h[x*2].v) * h[x*2+1].v) mod mo;
	end;
end;

procedure enter(x,i:longint);
var	y:longint;
begin
	y:=abs(x) mod hamo;
	while hash[y,1]<>0 do y:=(y+1) mod hamo;
	hash[y,1]:=i;
	hash[y,2]:=x
end;
function ha(x:longint):longint;
var	y:longint;
begin
	y:=abs(x) mod hamo;
	while hash[y,2]<>x do y:=(y+1) mod hamo;
	exit(hash[y,1]);
end;
begin
	assign(input,'segment.in');reset(input);
	//assign(output,'segment.out');rewrite(output);
	readln(n);
	for i:=1 to n do begin
		read(q[i,1],q[i,2],q[i,3]);
		if q[i,1]<>2 then read(q[i,4]);
		inc(t); a[t]:=q[i,2];
		inc(t); a[t]:=q[i,3];
	end;
	qsort(a,1,t);
	kk:=a[1];
	for i:=2 to t do begin
		if kk<>a[i] then begin
			inc(sum);
			enter(kk,sum);
			len[sum]:=a[i]-kk;
			kk:=a[i];
		end;
	end;
	inc(sum); enter(a[t],sum); dec(sum);
	maketree(1,1,sum);

	for i:=1 to n do begin
		x:=ha(q[i,2]);
		y:=ha(q[i,3])-1;
		case q[i,1] of
			0:begin
				z:=q[i,4];
				modify1(1,1,sum,x,y,z);
			end;
			1:begin
				z:=q[i,4];
				modify2(1,1,sum,x,y,z);
			end;
			2:begin
				ret:=1;
				query(1,1,sum,x,y);
				writeln(ret);
			end;
		end;
	end; 
	close(input);close(output);
end.
