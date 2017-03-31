object mpDemo: TmpDemo
  Left = 0
  Top = 0
  Caption = 'mpDemo'
  ClientHeight = 395
  ClientWidth = 759
  Color = clGradientInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object sgFiles: TStringGrid
    Left = 0
    Top = 51
    Width = 759
    Height = 320
    Align = alClient
    BevelKind = bkFlat
    BevelOuter = bvRaised
    BevelWidth = 2
    BiDiMode = bdLeftToRight
    Color = clHighlightText
    ColCount = 4
    DefaultColWidth = 250
    DefaultRowHeight = 16
    DrawingStyle = gdsGradient
    FixedColor = clAppWorkSpace
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Arial Unicode MS'
    Font.Style = []
    Font.Quality = fqClearType
    GradientStartColor = clCream
    GridLineWidth = 2
    ParentBiDiMode = False
    ParentFont = False
    PopupMenu = PopupMenu
    ScrollBars = ssVertical
    TabOrder = 0
    OnMouseDown = sgFilesMouseDown
    ExplicitTop = 35
    ExplicitHeight = 336
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 371
    Width = 759
    Height = 24
    Panels = <
      item
        Width = 50
      end>
    SimpleText = 'dfg'
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 759
    Height = 51
    Align = alTop
    TabOrder = 2
    object Button1: TButton
      Left = 16
      Top = 4
      Width = 75
      Height = 25
      Caption = #1061#1077#1096' '#1092#1072#1081#1083#1072'..'
      TabOrder = 0
      OnClick = Button1Click
    end
    object ProgressBar: TProgressBar
      Left = 97
      Top = 9
      Width = 635
      Height = 16
      TabOrder = 1
      Visible = False
    end
  end
  object Memo: TMemo
    Left = 512
    Top = 98
    Width = 231
    Height = 257
    ScrollBars = ssVertical
    TabOrder = 3
    Visible = False
  end
  object chbLog: TCheckBox
    Left = 16
    Top = 31
    Width = 97
    Height = 17
    Caption = #1051#1086#1075
    TabOrder = 4
    OnClick = chbLogClick
  end
  object MainMenu1: TMainMenu
    Left = 592
    Top = 32
    object N1: TMenuItem
      Caption = #1057#1082#1072#1085' '#1076#1080#1088#1077#1082#1090#1086#1088#1080#1080
      object N2: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1099#1081'..'
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object N4: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Enabled = False
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object N7: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N7Click
      end
    end
    object N8: TMenuItem
      Caption = #1054#1087#1077#1088#1072#1094#1080#1080
      object N11: TMenuItem
        Caption = #1054#1073#1085#1086#1074#1080#1090#1100' '#1089#1082#1072#1085
        Enabled = False
        OnClick = N11Click
      end
    end
    object N13: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = N13Click
    end
  end
  object PopupMenu: TPopupMenu
    Left = 400
    Top = 224
    object N12: TMenuItem
      Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1093#1077#1096
    end
  end
  object SaveDialog: TSaveDialog
    Filter = 'Scan Files|*.scfl'
    Left = 448
    Top = 104
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 336
    Top = 120
  end
  object ScanFileOpenDialog: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <
      item
        DisplayName = 'ScanFile'
        FileMask = '*.scfl'
      end>
    Options = []
    Left = 256
    Top = 216
  end
end
