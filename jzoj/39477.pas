var
        a:array[0..100000,1..3] of longint;
        b:array[0..100000,1..2] of longint;
        tree:array[0..400000] of longint;
        i,j,k,l,t,n,m,ans:longint;
function max(a,b:longint):longint;
begin
        if a>b then exit(a) else exit(b);
end;
procedure qsort1(i,j:longint);
var
        l,r,mid,mid1:longint;
begin
        l:=i;
        r:=j;
        mid:=a[(i+j) div 2,1];
        mid1:=a[(i+j) div 2,2];
        repeat
        while (a[i,1]<mid)or(a[i,1]=mid)and(a[i,2]<mid1) do inc(i);
        while (a[j,1]>mid)or(a[j,1]=mid)and(a[j,2]>mid1) do dec(j);
        if i<=j then
        begin
                a[0]:=a[i];
                a[i]:=a[j];
                a[j]:=a[0];
                inc(i);
                dec(j);
        end;
        until i>j;
        if i<r then qsort1(i,r);
        if l<j then qsort1(l,j);
end;
procedure qsort2(i,j:longint);
var
        l,r,mid:longint;
begin
        l:=i;
        r:=j;
        mid:=b[(i+j) div 2,1];
        repeat
        while (b[i,1]<mid) do inc(i);
        while (b[j,1]>mid) do dec(j);
        if i<=j then
        begin
                b[0]:=b[i];
                b[i]:=b[j];
                b[j]:=b[0];
                inc(i);
                dec(j);
        end;
        until i>j;
        if i<r then qsort2(i,r);
        if l<j then qsort2(l,j);
end;
function query(p,l,r,a,b:longint):longint;
var
        mid:longint;
begin
        if (l=a)and(r=b) then
        begin
                exit(tree[p]);
        end;
        mid:=(l+r) div 2;
        if a>mid then exit(query(p*2+1,mid+1,r,a,b))
        else if b<=mid then exit(query(p*2,l,mid,a,b))
        else exit(max(query(p*2,l,mid,a,mid),query(p*2+1,mid+1,r,mid+1,b)));
end;
procedure change(p,l,r,a,b:longint);
var
        mid:longint;
begin
        if l=r then
        begin
                tree[p]:=b;
                exit;
        end;
        mid:=(l+r) div 2;
        if a<=mid then change(p*2,l,mid,a,b) else change(p*2+1,mid+1,r,a,b);
        tree[p]:=max(tree[p*2],tree[p*2+1]);
end;
begin
	assign(input,'3947.in');reset(input);
	//assign(output,'.out');rewrite(output);

        readln(n,m,k);
        l:=0;
        for i:=1 to k do
        begin
                readln(a[i,1],a[i,2],a[i,3])
        end;
        qsort1(1,k);
        for i:=1 to k do
        begin
                b[i,1]:=a[i,2];
                b[i,2]:=i;
        end;
        qsort2(1,k);
        l:=0;
        b[0,1]:=-1;
        for i:=1 to k do
        begin
                if b[i,1]<>b[i-1,1] then inc(l);
                a[b[i,2],2]:=l;
        end;
        for i:=1 to k do
        begin
                t:=query(1,1,k,1,a[i,2])+a[i,3];
                change(1,1,k,a[i,2],t);
        end;
        writeln(query(1,1,k,1,k));
end.
