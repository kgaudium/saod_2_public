using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;


namespace RegExpLab
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = " фыидо, fjbld33- 2олт?";
            Console.WriteLine(str);

            // Console.WriteLine(re.Replace(str, "$1$4$3$2$5$6$7"));
            // MatchCollection mc = re.Matches(str);
            // foreach (var m in mc)
            //     Console.WriteLine(m);
            
            string orig;
            try
            {
                using (StreamReader sr = new StreamReader("Dictionary.xml"))
                {
                    orig  = sr.ReadToEnd();
                    Console.WriteLine(orig.Length);
                    
                    // First defect
                    Regex regexEmptyNotStruct = new Regex(@"<((?!main-word)(?!article)(?!example)[a-z-]+)>([^\w]*)</\1>");
                    
                    // Print all matches to console
                    // MatchCollection mc1 = regexEmptyNotStruct.Matches(orig);
                    // foreach (var m in mc1)
                    //     Console.WriteLine(m);

                    // Replace all matches
                    var transformed = regexEmptyNotStruct.Replace(orig, "$2");

                    // Prints transformed string
                    // Console.WriteLine(transformed);

                    // Prints all matches in transformed string (excpect nothing)
                    MatchCollection mc2 = regexEmptyNotStruct.Matches(transformed);
                    foreach (var m in mc2)
                        Console.WriteLine(m);
                    
                    
                    // Second defect
                    Regex regexSpaceBeforePunct = new Regex(@"\s+([,.:?!])");
                    
                    // Print all matches to console
                    // MatchCollection mc3 = regexSpaceBeforePunct.Matches(transformed);
                    // foreach (var m in mc3)
                    //     Console.WriteLine(m);

                    // Replace all matches
                    transformed = regexSpaceBeforePunct.Replace(transformed, "$1");

                    // Prints transformed string
                    // Console.WriteLine(transformed);

                    // Prints all matches in transformed string (expect nothing)
                    MatchCollection mc4 = regexSpaceBeforePunct.Matches(transformed);
                    foreach (var m in mc4)
                        Console.WriteLine(m);
                    
                    // Trying to parse XML, expect no exceptions
                    XmlDocument xml = new XmlDocument();
                    xml.LoadXml(transformed);
                    
                    try
                    {
                        using (StreamWriter sw = new StreamWriter("newXml.xml"))
                        {
                            sw.Write(transformed);
                        }
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine("Ошибка сохранений в файл: \"{0}\"\n{1}", "newXml.xml", ex);
                        return;
                    }

                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка чтения файла: \"Dictionary.xml\"\n{0}", ex);
                return;
            }

        }
    }
}
