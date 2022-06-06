using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using Lab3.repository;
using Lab3_Csharp_Interfata.service;
using log4net;

namespace Lab3_Csharp_Interfata
{
    static class Program
    {
        private static readonly ILog logger = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            IDictionary<String, string> props = new SortedList<String, String>();
            props.Add("ConnectionString", GetConnectionStringByName("concurs.db"));
            log4net.Config.XmlConfigurator.Configure(new FileInfo("log4net.xml"));
            RepositoryParticipantDB repoParticipant = new RepositoryParticipantDB(props);
            RepositoryOrganizator repoOrganizator = new RepositoryOrganizatorDB(props);
            RepositoryInscriereDB repoInscriere = new RepositoryInscriereDB(props);
            ServiceParticipant serviceParticipant = new ServiceParticipant(repoParticipant);
            ServiceOrganizator serviceOrganizator = new ServiceOrganizator(repoOrganizator);
            ServiceInscriere serviceInscriere = new ServiceInscriere(repoInscriere);
            Service service = new Service(serviceParticipant, serviceOrganizator, serviceInscriere); 
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1(service));
        }
        static string GetConnectionStringByName(string name)
        {
            // Assume failure.
            string returnValue = null;

            // Look for the name in the connectionStrings section.
            ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings[name];

            // If found, return the connection string.
            if (settings != null)
                returnValue = settings.ConnectionString;

            return returnValue;
        }
    }
}