Const
    SIZE = 200;

Type
    hugeint = Record
        len : Integer;
        num : Array[1..SIZE] Of Integer;
    End; 
    //len表示大整数的位数;num[1]表示个位、num[2]表示十位,以此类推

Var
    s : String;
    i : Integer;
    target, left, middle, right : hugeint;

Function times(a, b : hugeint) : hugeint; 
// 计算大整数 a 和 b 的乘积
    Var
        i, j : Integer;
        ans : hugeint; 
    Begin
        FillChar(ans, SizeOf(ans), 0);
        For i := 1 To a.len Do
            For j := 1 To b.len Do
                    ans.num[i + j - 1]:= ans.num[i + j - 1] + a.num[i] * b.num[j];
        For i := 1 To a.len + b.len Do
            Begin
                ans.num[i + 1] := ans.num[i + 1] + ans.num[i] DIV 10;
                    ans.num[i] := ans.num[i] mod 10;    ;
                If ans.num[a.len + b.len] > 0
                    Then ans.len := a.len + b.len
                    Else ans.len := a.len + b.len - 1;
            End;
        times := ans; 
    End;

Function add(a, b : hugeint) : hugeint; 
// 计算大整数 a 和 b 的和
    Var
        i : Integer;
        ans : hugeint; 
    Begin
        FillChar(ans.num, SizeOf(ans.num), 0);
        If a.len > b.len
            Then ans.len := a.len
            Else ans.len := b.len;
        For i := 1 To ans.len Do
            Begin
                ans.num[i] :=ans.num[i] + a.num[i] + b.num[i]; ;
                ans.num[i + 1] := ans.num[i + 1] + ans.num[i] DIV 10;
                ans.num[i] := ans.num[i] MOD 10;
            End;
        If ans.num[ans.len + 1] > 0
            Then Inc(ans.len);
        add := ans;
    End;

Function average(a, b : hugeint) : hugeint; 
// 计算大整数 a 和 b 的平均数的整数部分
    Var
        i : Integer;
        ans : hugeint; 
    Begin
        ans := add(a, b);
        For i := ans.len DownTo 2 Do
            Begin
                ans.num[i - 1] := ans.num[i - 1] + (    ans.num[i] mod 2   ) * 10;
                ans.num[i] := ans.num[i] DIV 2;
            End;
        ans.num[1] := ans.num[1] DIV 2;
        If ans.num[ans.len] = 0
            Then Dec(ans.len);
        average := ans; 
    End;

Function plustwo(a : hugeint) : hugeint; 
// 计算大整数 a 加 2 后的结果
    Var
        i : Integer;
        ans : hugeint; 
    Begin
        ans := a;
        ans.num[1] := ans.num[1] + 2;
        i := 1;
        While (i <= ans.len) AND (ans.num[i] >= 10) Do
        Begin
            ans.num[i + 1] := ans.num[i + 1] + ans.num[i] DIV 10;
            ans.num[i] := ans.num[i] MOD 10;
            Inc(i);
        End;
        If ans.num[ans.len + 1] > 0
            Then   inc(ans.len)    ;
        plustwo := ans; 
    End;

Function over(a, b : hugeint) : Boolean; 
// 若大整数 a > b 则返回 1, 否则返回 0
    Var
        i : Integer; 
    Begin
        If (    a.len<b.len     ) Then
            Begin
                over := FALSE;
                Exit;
            End;
        If a.len > b.len Then
            Begin
                over := TRUE;
                Exit;
            End;
        For i := a.len DownTo 1 Do
            Begin
                If a.num[i] < b.num[i] Then
                    Begin
                        over := FALSE;
                        Exit;
                    End;
                If a.num[i] > b.num[i] Then
                    Begin
                        over := TRUE;
                        Exit;
                    End;
            End;
        over := FALSE; 
    End;

Begin
    Readln(s);
    FillChar(target.num, SizeOf(target.num), 0);
    target.len := Length(s);
    For i := 1 To target.len Do
        target.num[i] := Ord(s[target.len - i + 1]) -   ord('0')   ;
    FillChar(left.num, SizeOf(left.num), 0);
    left.len := 1;
    left.num[1] := 1;
    right := target;
    Repeat
        middle := average(left, right);
        If over(  times(middle, middle), target  )
            Then right := middle
            Else left := middle;
    Until over(plustwo(left), right);
    For i := left.len DownTo 1 Do
        Write(left.num[i]);
    Writeln;
End. 


