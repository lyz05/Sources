type
        arr=array[0..500001] of longint;
        arr1=array[0..11] of longint;
var
        y:arr1;
        x:int64;
        num:arr;
        m,k,i,j,l,t,z:longint;
        a:array[0..11] of arr;
        h1:array[0..1000001] of arr1;
        h,la:array[0..1000001] of longint;
procedure qsort(var x:arr; l,r:longint);
var
        i,j,mid:longint;
begin
        i:=l; j:=r;
        mid:=x[random(j-i+1)+i];
        while i<=j do begin
                while x[i]<mid do inc(i);
                while x[j]>mid do dec(j);
                if i<=j then begin
                        x[0]:=x[i]; x[i]:=x[j]; x[j]:=x[0];
                        inc(i); dec(j);
                end;
        end;
        if i<r then qsort(x,i,r);
        if l<j then qsort(x,l,j);
end;
procedure swap(var a,b:longint);
var
        c:longint;
begin
        c:=a; a:=b; b:=c;
end;
procedure swap1(var a,b:arr1);
var
        c:arr1;
begin
        c:=a; a:=b; b:=c;
end;
procedure ss(i,i1:longint);
begin
        swap(h[i],h[i1]);
        swap(la[i],la[i1]);
        swap1(h1[i],h1[i1]);
end;
procedure up(i:longint);
var
        i1:longint;
begin
        if i=1 then exit;
        i1:=i shr 1;
        if h[i]<h[i1] then begin
                ss(i,i1);
                up(i1);
        end;
end;
procedure down(i:longint);
var
        l,r:longint;
begin
        l:=i*2; r:=l+1;
        if i>=t then exit;
        if h[l]<h[r] then begin
                if h[l]<h[i] then begin
                        ss(i,l);
                        down(l);
                end;
        end else begin
                if h[r]<h[i] then begin
                        ss(i,r);
                        down(r);
                end;
        end;
end;
begin
        fillchar(h,sizeof(h),$7f);
        randomize;
        readln(m,k);
        t:=1;
        for i:=1 to m do begin
                read(num[i]);
                for j:=1 to num[i] do read(a[i,j]);
                qsort(a[i],1,num[i]);
        end;
        h[1]:=0;
        for i:=1 to m do begin
                h[1]:=h[1]+a[i,1];
                h1[1,i]:=1;
                la[1]:=1;
        end;

        t:=1;
        for i:=2 to k do begin
                x:=h[1];
                y:=h1[1];
                z:=la[1];
                h[1]:=maxlongint;
                down(1);
                for j:=z to m do if y[j]<num[j] then begin
                        inc(t);
                        h[t]:=x-a[j,y[j]]+a[j,y[j]+1];
                        h1[t]:=y;
                        inc(h1[t,j]);
                        la[t]:=j;
                        up(t);
                end;
        end;
        writeln(h[1]);
end.
input
3 4
2 2 3
3 2 3 4
1 1

output
7
