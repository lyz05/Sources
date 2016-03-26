const mo=100000000;
var l,n,k,i,z,j:longint;
    s:ansistring;
    a,b,c,d:array[0..6000]of longint;
function check:boolean;
var i:longint;
begin
    if z>a[0] then exit(true);
    if z<a[0] then exit(false);
    for i:=a[0] downto 1 do if a[i]<d[i] then exit(true)
    else if a[i]>d[i] then exit(false);
    exit(false);
end;
procedure new;
var l,m:longint;
begin
    m:=0;
    for i:=1 to b[0] do begin
        b[i]:=b[i] shl 1+m;
        m:=b[i] div mo;
        b[i]:=b[i] mod mo;
    end;
    if m>0 then begin
        inc(b[0]);
        b[b[0]]:=m;
        m:=0;
    end;
    l:=1;
    dec(b[1]);
    while b[l]<0 do begin
          inc(b[l],mo);
          inc(l);
          dec(b[l]);
    end;
    while b[b[0]]=0 do dec(b[0]);
    for i:=1 to c[0] do begin
        c[i]:=c[i] shl 1+m;
        m:=c[i] div mo;
        c[i]:=c[i] mod mo;
    end;
    if m>0 then begin
        inc(c[0]);
        c[c[0]]:=m;
    end;
    l:=1;
    dec(c[1],3);
    while c[l]<0 do begin
          inc(c[l],mo);
          inc(l);
          dec(c[l]);
    end;
    while c[c[0]]=0 do dec(c[0]);
    for i:=1 to c[0] do begin
        a[i]:=a[i]+c[i];
        a[i+1]:=a[i+1]+a[i] div mo;
        a[i]:=a[i] mod mo;
    end;
    l:=c[0];
    while a[l+1]>=mo do begin
          inc(l);
          a[l+1]:=a[l+1]+a[l] div mo;
          a[l]:=a[l] mod mo;
    end;
    while a[a[0]+1]>0 do inc(a[0]);
end;
procedure answer;
var s:string[4];
    j:longint;
begin
    for i:=1 to z do begin
        a[i]:=a[i]-d[i];
        if a[i]<0 then begin
           dec(a[i+1]);
           inc(a[i],mo);
        end;
    end;
    if n>3 then while a[a[0]]=0 do dec(a[0]);
    for i:=1 to a[0] do begin
        b[i]:=b[i]-a[i];
        if b[i]<0 then begin
            inc(b[i],mo);
            dec(b[i+1]);
        end;
    end;
    while b[b[0]]=0 do dec(b[0]);
    write(b[b[0]]);
    for i:=b[0]-1 downto 1 do begin
        for j:=1 to 7-trunc(ln(b[i])/ln(10)) do write('0');
        write(b[i]);
    end;
end;
begin
    readln(s);
    l:=pos(' ',s);
    k:=length(s);
    val(copy(s,1,l-1),n);
    if n<3 then begin
        writeln(-1);
        halt;
    end;
    j:=k-l;
    z:=j shr 3;
    j:=j-z shl 3;
    for i:=1 to z do val(copy(s,k-i shl 3+1,8),d[i]);
    if j>0 then begin
        inc(z);
        val(copy(s,l+1,j),d[z]);
    end;
    a[0]:=1;
    a[1]:=n;
    b[0]:=1;
    b[1]:=n;
    c[0]:=1;
    c[1]:=n;
    while check do new;
    answer;
end.
