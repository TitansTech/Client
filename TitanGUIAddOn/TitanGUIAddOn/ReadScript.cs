using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace TitanGUIAddOn
{
    class ReadScript
    {
        public SMDToken CurrentToken;
        public decimal TokenNumber;
        public string TokenString;

        private StreamReader r;
        private char ch;
        private int num = 0;

        public enum SMDToken
        {
            NAME,
            NUMBER,
            END,
            COMMAND = '#',
            LP = '{',
            RP = '}',
            COMMA = ',',
            PLUS = '+',
            SEMICOLON = ';',
            SMD_ERROR
        };

        public ReadScript(string FilePath)
        {
            r = new StreamReader(FilePath);
        }

        private int Read()
        {
            char[] charray = new char[1];
            int x = r.Read(charray, 0, 1);
            ch = charray[0];
            num++;
            return x;
        }

        public SMDToken GetToken()
        {
            TokenString = "";
            do
            {
                if (Read() == 0)
                    return SMDToken.END;
                else
                {
                    if (ch == '/')
                    {
                        if(Read() != 0)
                        {
                            if (ch == '/')
                            {
                                while (ch != '\n')
                                {
                                    if(Read() == 0)
                                    {
                                        r.Close();
                                        return SMDToken.END;
                                    }
                                }
                            }
                        }
                    }
                }

                //if(ch=file.
            } while (Char.IsWhiteSpace(ch) != false);

            switch (ch)
            {
                case '#':
                    {
                        return CurrentToken = SMDToken.COMMAND;
                    } break;
                case ';':
                    {
                        return CurrentToken = SMDToken.SEMICOLON;
                    } break;
                case ',':
                    {
                        return CurrentToken = SMDToken.COMMA;
                    } break;
                case '{':
                    {
                        return CurrentToken = SMDToken.LP;
                    } break;
                case '}':
                    {
                        return CurrentToken = SMDToken.RP;
                    } break;
                case '-':
                case '.':
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    {
                        string tmp = "";
                        tmp += ch;
                        if (Read() != 0)
                        {
                            while ((ch == '.') || (Char.IsDigit(ch)))
                            {
                                tmp += ch;
                                if (Read() == 0)
                                    break;
                            }
                        }
                        TokenNumber = Convert.ToDecimal(tmp);
                        return CurrentToken = SMDToken.NUMBER;
                    } break;
                case '\"':
                    {
                        string tmp = "";
                        //tmp += ch;
                        if (Read() != 0)
                        {
                            while (ch != '\"')
                            {
                                tmp += ch;
                                if (Read() == 0)
                                    break;
                            }
                            if (ch == '\"')
                            {
                                num--;
                            }
                        }
                        TokenString = tmp;
                        return CurrentToken = SMDToken.NAME;
                    } break;
                default:
                    {
                        if (Char.IsLetter(ch))
                        {
                            string tmp = "";
                            tmp += ch;
                            if (Read() != 0)
                            {
                                while ((ch == '.') || (ch == '_') || (Char.IsLetterOrDigit(ch)))
                                {
                                    tmp += ch;
                                    if (Read() == 0)
                                        break;
                                }
                            }
                            TokenString = tmp;
                            return CurrentToken = SMDToken.NAME;
                        }
                        else
                        {
                            return CurrentToken = SMDToken.SMD_ERROR;
                        }
                    } break;
            }
            return SMDToken.NAME;
        }
    }
}
