const maxn=500000;
var
        h,s,d:array[0..maxn]of int64;
        a:array[0..maxn]of int64;
        tz,tf:array[1..4*maxn]of int64;
        g:array[0..maxn,1..2]of int64;
        n,i,x,j,k:longint;
        mm:int64;
function min(x,y:int64):int64;
begin
        if x<y then exit(x)else exit(y);
end;
procedure qsort(l,r:longint);
var
        i,j:longint;
        mid:int64;
begin
        i:=l;j:=r;
        mid:=g[(l+r)>>1,1];
        while i<j do
        begin
                while(i<r)and(g[i,1]<mid)do inc(i);
                while(l<j)and(mid<g[j,1])do dec(j);
                if i<=j then
                begin
                        g[0]:=g[i];
                        g[i]:=g[j];
                        g[j]:=g[0];
                        inc(i);
                        dec(j);
                end;
        end;
        if i<r then qsort(i,r);
        if l<j then qsort(l,j);
end;
procedure changez(t,l,r,x:longint;v:int64);
var
        mid:longint;
begin
        if l=r then
        begin
                tz[t]:=min(tz[t],v);
                exit;
        end;
        mid:=(l+r)>>1;
        if x<=mid then changez(t<<1,l,mid,x,v)
        else changez(t*2+1,mid+1,r,x,v);
        tz[t]:=min(tz[t<<1],tz[t*2+1]);
end;
procedure changef(t,l,r,x:longint;v:int64);
var
        mid:longint;
begin
        if l=r then
        begin
                tf[t]:=min(tf[t],v);
                exit;
        end;
        mid:=(l+r)>>1;
        if x<=mid then changef(t<<1,l,mid,x,v)
        else changef(t*2+1,mid+1,r,x,v);
        tf[t]:=min(tf[t<<1],tf[t*2+1]);
end;
function getminz(t,l,r,x,y:longint):int64;
var
        mid:longint;
begin
        if (l=x)and(r=y) then exit(tz[t]);
        mid:=(l+r)>>1;
        if y<=mid then exit(getminz(t<<1,l,mid,x,y))
        else
        if x>mid then exit(getminz(t*2+1,mid+1,r,x,y))
        else
        exit(min(getminz(t<<1,l,mid,x,mid),getminz(t*2+1,mid+1,r,mid+1,y)));
end;
function getminf(t,l,r,x,y:longint):int64;
var
        mid:longint;
begin
        if (l=x)and(r=y) then exit(tf[t]);
        mid:=(l+r)>>1;
        if y<=mid then exit(getminf(t<<1,l,mid,x,y))
        else
        if x>mid then exit(getminf(t*2+1,mid+1,r,x,y))
        else
        exit(min(getminf(t<<1,l,mid,x,mid),getminf(t*2+1,mid+1,r,mid+1,y)));
end;
begin
        readln(n);
        for i:=1 to n do read(h[i]);
        for i:=1 to n do begin 
			g[i,1]:=h[i];
			g[i,2]:=i;
	   end;
        for i:=1 to n do s[i]:=s[i-1]+abs(h[i]-h[i-1]);
        qsort(1,n);
        k:=0;
        g[0,1]:=-100;
        for i:=1 to n do
        begin
                if g[i,1]<>g[i-1,1] then inc(k);
                d[g[i,2]]:=k;
        end;
	   
        fillchar(tz,sizeof(tz),$7f);
        fillchar(tf,sizeof(tf),$7f);
        for i:=1 to n do
        begin
                if i<n then a[i]:=s[i]+h[i+1] else a[i]:=s[i];
                if i<n then a[i]:=min(a[i],min(getminf(1,1,k,1,d[i+1])+h[i+1],getminz(1,1,k,d[i+1],k)-h[i+1])+s[i])
                else begin 
			     a[i]:=min(a[i],mm+s[i]);
				break;
		      end;
                changez(1,1,k,d[i],a[i]-s[i+1]+h[i]);
                changef(1,1,k,d[i],a[i]-s[i+1]-h[i]);
                if a[i]-s[i+1]<mm then mm:=a[i]-s[i+1];
        end;
        writeln(a[n]);
end.
